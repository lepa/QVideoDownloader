#include "youporn.h"

void Youporn::findDownLink()
{
    Download* dl;
    QString* content;
    QRegExp rx ("(http://download.youporn.com/.+?&ll=1)");
    int pos;

    dl = new Download(this->watchLink);
    dl->setCookie("Cookie: age_check=1");
    content = dl->getContent();
    delete dl;

    if ( (pos = rx.indexIn(*content)) > -1 )
    {
        this->downLink = rx.cap(1);
    }
    else
    {
        YpBadUrl ypbadurl;
        throw ypbadurl;
    }
}
