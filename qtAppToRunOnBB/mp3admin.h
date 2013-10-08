#ifndef MP3ADMIN_H
#define MP3ADMIN_H
#include <QString>
#include <gst/gst.h>
#include <glib.h>
#include <QVector>
#include <QFileDialog>

class mp3Admin
{


    public:


        static bool _play;

        mp3Admin();
        void playStopSong(bool isRemote, QString actualSongPath, QString ip, int _portNumber);
        bool getPlayFlag();
        void setPlayFlag(bool value);
        void pauseLocalSong();
        void pauseRemoteSong(int indexPipeline);
        void stopRemoteSong(int indexPipeline);

        void setPathList(QFileInfoList list);
        QFileInfoList getPathList();
        QString getPreviewPath(QString actualPath);
        QString getNextPath(QString actualPath);


    private:
        QFileInfoList _pathList; //
        GstElement *pipelineLocal;
        QVector<GstElement**> listPipelines;
        static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data);
        static gboolean timeout_callback(gpointer data);

        QString getPrevOrNextPath(QString actualPath, int moveCount);

};

#endif // MP3ADMIN_H
