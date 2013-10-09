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
        void playLocal(QString actualSongPath);
        bool getPlayFlag();
        void setPlayFlag(bool value);
        void pauseLocalSong();
        void pauseRemoteSong(int indexPipeline);
        void stopRemoteSong(int indexPipeline, QString actualSongPath);
        void setPathList(QFileInfoList list);
        QFileInfoList getPathList();
        QString getPreviewPath(QString actualPath);
        QString getNextPath(QString actualPath);
        void playRemote(int index, QString actualSongPath, QString ip, int _portNumber);

    private:
        QFileInfoList _pathList; //
        QVector<QString> listIP;
        QVector<int> listPorts;
        GstElement *pipelineLocal;
        QVector<GstElement**> listPipelines;
        QString getPrevOrNextPath(QString actualPath, int moveCount);
        static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data);
        static gboolean timeout_callback(gpointer data);
};

#endif // MP3ADMIN_H
