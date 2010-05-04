#include "megavideo.h"
#include <iostream>

void Megavideo::setUrl (const QString& link)
{
    QRegExp rx ("\\?v=(\\w{8})$", Qt::CaseSensitive, QRegExp::RegExp2);
    if (rx.indexIn (link) != -1)
        this->watchLink = "http://www.megavideo.com/xml/videolink.php?v=" + rx.cap(1);
    else {
        MvBadUrl exc;
        throw exc;
    }
    this->findDownLink ();
}

void Megavideo::findDownLink()
{
    Download* dl;
    QRegExp rx;
    QString* content;

    dl = new Download(this->watchLink);
    content = dl->getContent();
    delete dl;


    rx.setPattern("k1=\"(.+?)\"");
    if (rx.indexIn(*content) != -1)
        this->data.k1 = rx.cap(1);

     rx.setPattern("k2=\"(.+?)\"");
     if (rx.indexIn(*content) != -1)
        this->data.k2 = rx.cap(1);

    rx.setPattern("un=\"(.+?)\"");
    if (rx.indexIn(*content) != -1)
        this->data.un = rx.cap(1);

    rx.setPattern("s=\"(.+?)\"");
    if (rx.indexIn(*content) != -1)
        this->data.s = rx.cap(1);

    this->decode ();
    this->downLink =  "http://www" + this->data.s + ".megavideo.com/files/" + this->data.final;
    delete content;
}

void Megavideo::decode()
{
    bool tmp, block [128];
    int i, x, cipher, offset, ciphers [384];
    char ch, chunks [32];

    std::string un = this->data.un.toStdString();
    int k1 = this->data.k1.toInt();
    int k2 = this->data.k2.toInt();

    for (i = 0; i < 32; i++) {
        ch = un.at (i);
        ch = (ch - 48 - (ch >= 'a' && ch <= 'f') ? 39 : 0);
        for (x = 1; x <= 4; x++) {
            block [i * 4 - x] = ch % 2;
            ch /= 2;
        }
    }

    for (i = 0; i < 384; i++) {
        k1 = (k1 * 11 + 77213) % 81371;
        k2 = (k2 * 17 + 92717) % 192811;
        ciphers [i] = (k1 + k2) % 128;
    }

    for (i = 256; i >= 0; --i) {
        cipher = ciphers [i];
        offset = i % 128;
        tmp = block [cipher];
        block [cipher] = block [offset];
        block [offset] = tmp;
    }

    for (i = 0; i < 128; ++i)
        block [i] = block [i] ^ ciphers [i + 256] & 1;

    for(i = 0; i < 128; i += 4)
        chunks [i] = block [i] * 8 + block [i + 1] * 4 + block [i + 2] * 2 + block [i +3];

    for (i = 0; i < 32; i++)
        chunks [i] += 48 + (chunks [i] >= 10 && chunks [i] <= 15) ? 39 : 0;

    this->data.final = *chunks;
}
