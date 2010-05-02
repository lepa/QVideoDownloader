#include "youjizz.h"

void Youjizz::findDownLink()
{
    Download* dl;
    QRegExp rx ("so\\.addVariable\\(\"file\",\"(.+?)\"\\)");
    QString* content;
    int pos;

    dl = new Download(this->watchLink);
    content = dl->getContent();
    delete dl;

    if ( (pos = rx.indexIn(*content)) > -1)
    {
        this->downLink = rx.cap(1);
    }
    else
    {
        YjBadUrl e;
        throw e;
    }

    delete content;
}
