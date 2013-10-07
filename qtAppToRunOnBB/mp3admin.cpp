#include "mp3admin.h"
#include <gst/gst.h>
#include <glib.h>
#include <QFileDialog>

mp3Admin::mp3Admin()
{
}


void mp3Admin::setPathList(QFileInfoList list)   //
{
    _pathList = list;
}

QFileInfoList mp3Admin::getPathList()       //
{
    return _pathList;
}

QString mp3Admin::getNextPath(QString actualPath)
{
    return getPrevOrNextPath(actualPath, 1);
}

QString mp3Admin::getPreviewPath(QString actualPath)
{
    return getPrevOrNextPath(actualPath, -1);
}

QString mp3Admin::getPrevOrNextPath(QString actualPath, int moveCount)
{
    //  Armar QFileInfo del actualPath para buscarlo en la lista de paths
    QFileInfo actualPathInfo(actualPath);
    // Busarlo
    int indexActualPath = _pathList.indexOf(actualPathInfo);
    // Retornar el siguiente path
    QString returnPath = (0 <= (indexActualPath+moveCount) && (indexActualPath+moveCount) < _pathList.count())? _pathList.at(indexActualPath+moveCount).filePath() : "END";

    QByteArray bb = returnPath.toLatin1();
    const char *ss = bb.data();

    printf("returned path is: %s", ss);
    return returnPath;
}


extern "C" void bus_call (GstBus *bus, GstMessage *msg, gpointer data);
gboolean mp3Admin::bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
    GMainLoop *loop = (GMainLoop *) data;



    switch (GST_MESSAGE_TYPE (msg))
    {
        case GST_MESSAGE_EOS:
            g_print ("End of stream\n");
            g_main_loop_quit (loop);
            break;

            case GST_MESSAGE_ERROR:
        {
                gchar  *debug;
                GError *error;

                gst_message_parse_error (msg, &error, &debug);
                g_free (debug);

                g_printerr ("Error: %s\n", error->message);
                g_error_free (error);

                g_main_loop_quit (loop);
                break;
            }
            default:
            break;
    }
    return TRUE;
}


//##########################################################################
// This program plays a OGG file
// Copyright (C) 2013  Elias Mendez Chacon, Wagner Martinez Romero, Wilbeth Cespedes
// Code taken from http://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/chapter-helloworld.html
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
//#########################################################################
extern "C" void playStopSong(bool isRemote);
void mp3Admin::playStopSong(bool isRemote, QString actualSongPath, QString ip, int _portNumber)
{
    QByteArray ba = actualSongPath.toLatin1();
    const char *_actualSongPath = ba.data();

    QByteArray bb = ip.toLatin1();
    const char *_ip = bb.data();

    printf("songPath: %s \n", _actualSongPath);
    printf("ip: %s \n", _ip);
    printf("portNumber: %i \n", _portNumber);
    printf("ip: %b \n", isRemote);

    if(isRemote){
        //Poner codigo udp -- parametro (nombre puerto ip)
        printf("ip: %s \n", "Entro con UDP");

        GMainLoop *loop;


            g_print ("Create elements of the pipeline");

            GstElement *pipeline, *inputfile, *decoder, *converter, *resampler, *encoder, *rtp, *sink;
            GstBus *bus;

            /* Initialisation */
            gst_init (NULL, FALSE);

            loop = g_main_loop_new (NULL, FALSE);

            /* Create gstreamer elements */
            pipeline = gst_pipeline_new("pipeline");

            inputfile = gst_element_factory_make("filesrc", "inputfile");
            g_object_set(G_OBJECT(inputfile), "location", _actualSongPath, NULL);

            decoder = gst_element_factory_make("mad", "mp3decoder");
            converter = gst_element_factory_make("audioconvert", "converter");
            resampler = gst_element_factory_make("audioresample", "resampler");
            encoder = gst_element_factory_make("mulawenc", "encoder");
            rtp = gst_element_factory_make("rtppcmupay", "player");
            sink = gst_element_factory_make("udpsink", "sink");

            g_object_set (G_OBJECT (sink), "port", _portNumber, "host", _ip, NULL);

            g_print ("Create elements of the pipeline\n");

            bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
            gst_bus_add_watch(bus, bus_call, NULL);
            g_print ("Bus Callback\n");

            gst_bin_add_many(GST_BIN(pipeline), inputfile, decoder, converter, resampler, encoder, rtp, sink, NULL);
            g_print ("Pipeline created\n");

            gst_element_link_many(inputfile, decoder, converter,
            resampler, encoder, rtp, sink, NULL);
            g_print ("Linking the elements\n");

            gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);
            g_print ("Start sending Stream\n");
            g_main_loop_run(loop);
            g_print ("End sending Stream\n");
    }
    else{
        //Poner codigo normal
        printf("ip: %s \n", "Entro en local");

        GMainLoop *loop;

            GstElement *pipeline, *source, *decoder, *conv, *resample, *sink;
            GstBus *bus;

            /* Initialisation */
            gst_init (NULL, FALSE);
            loop = g_main_loop_new (NULL, FALSE);

            /* Create gstreamer elements */
            pipeline = gst_pipeline_new ("audio-player");
            source  = gst_element_factory_make ("filesrc",      "file-source");
            decoder  = gst_element_factory_make ("mad",      "mp3-decoder");
            conv    = gst_element_factory_make ("audioconvert",  "converter");
            resample = gst_element_factory_make ("audioresample", "audio-resample");
            sink    = gst_element_factory_make ("autoaudiosink", "audio-output");

            if (!pipeline || !source || !decoder || !conv || !resample || !sink) {
                g_printerr ("One element could not be created. Exiting.\n");
            }
            else
            {
                /* Set up the pipeline */

                /* we set the input filename to the source element */
                g_object_set (G_OBJECT (source), "location", _actualSongPath, NULL);

                /* we add a message handler */
                bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
                gst_bus_add_watch (bus, bus_call, loop);
                gst_object_unref (bus);

                /* we add all elements into the pipeline */
                /* file-source | mp3-decoder | converter | resample | alsa-output */
                gst_bin_add_many (GST_BIN (pipeline), source, decoder, conv, resample, sink, NULL);

                /* we link the elements together */
                /* file-source -> mp3-decoder -> converter -> resample -> alsa-output */
                gst_element_link_many (source, decoder, conv, sink, NULL);

                /* Set the pipeline to "playing" state*/
                g_print ("Now playing: %s\n", _actualSongPath);
                gst_element_set_state (pipeline, GST_STATE_PLAYING);

                /* Iterate */
                g_print ("Running...\n");
                g_main_loop_run (loop);

                /* Out of the main loop, clean up nicely */
                g_print ("Returned, stopping playback\n");
                gst_element_set_state (pipeline, GST_STATE_NULL);
                g_print ("Deleting pipeline\n");
                gst_object_unref (GST_OBJECT (pipeline));
            }
    }
}


