#ifndef MP3ADMIN_H
#define MP3ADMIN_H
#include <QString>
#include <gst/gst.h>
#include <glib.h>
#include <QFileDialog>

class mp3Admin
{

    QFileInfoList _pathList; //

public:
    mp3Admin();
    void playStopSong(bool isRemote, QString actualSongPath, QString ip, int _portNumber);

    void setPathList(QFileInfoList list);     //
    QFileInfoList getPathList();              //
    QString getPreviewPath(QString actualPath); //
    QString getNextPath(QString actualPath);  //

private:
    static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data);
    QString getPrevOrNextPath(QString actualPath, int moveCount); //
};

#endif // MP3ADMIN_H
