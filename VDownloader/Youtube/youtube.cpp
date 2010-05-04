#include "youtube.h"

void Youtube::findDownLink()
{
    Download* dl;
    QRegExp rx ("(video_id=[^&]+).*(&t=[^&]+)");
    QString* content;
    int pos;

    dl = new Download(this->watchLink);
    content = dl->getContent();
    delete dl;

    if ( (pos = rx.indexIn(*content)) > -1)
    {
        this->downLink = "http://youtube.com/get_video?"+rx.cap(1)+rx.cap(2);
    }
    else
    {
        YtBadUrl e;
        throw e;
    }

    delete content;
}
