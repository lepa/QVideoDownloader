#include "download.h"


Download::Download(const char* url)
{
    this->link = url;
    this->cookies = "";
}

Download::Download(const std::string& url)
{
    this->link = url.c_str();
    this->cookies = "";
}

Download::Download(const QString& url)
{
    this->link = url;
    this->cookies = "";
}

Download& Download::operator =(const char* url)
{
    this->link = url;
    return *this;
}

Download& Download::operator =(const std::string& url)
{
    this->link = url.c_str();
    return *this;
}

Download& Download::operator =(const QString& url)
{
    this->link = url;
    return *this;
}

Download& Download::setUrl(const char* url)
{
    this->link = url;
    return *this;
}

Download& Download::setUrl(const std::string& url)
{
    this->link = url.c_str();
    return *this;
}

Download& Download::setUrl(const QString& url)
{
    this->link = url;
    return *this;
}

Download& Download::setCookie(const char* cookiestring)
{
    this->cookies = cookiestring;
    return *this;
}

Download& Download::setCookie(const QString& cookiestring)
{
    this->cookies = cookiestring;
    return *this;
}

Download& Download::setCookie(const std::string &cookiestring)
{
    this->cookies = cookiestring.c_str();
    return *this;
}

Download& Download::fileWrite(const QString& filename)
{
    QRegExp rx("http://(.+?)/");
    QTcpSocket sock;
    QString dns;
    QFile* file;
    char* buffer;
    int pos;

    if ( ( pos = rx.indexIn(this->link)) > -1)
    {
        dns = rx.cap(1);
    }
    else
    {
        throw *(new InvalidUrl);
    }

    sock.connectToHost(dns, 80);
    sock.write( ("GET "+this->link+"\r\n").toAscii() );

    file = new QFile(filename);
    file->open(QIODevice::WriteOnly);
    buffer = new char [100];
    int len;

    while ((len = sock.read(buffer, 100)) > 0)
    {
        file->write(buffer, len);
    }

    file->close();
    delete [] buffer;
    delete file;

    return *this;
}

Download& Download::fileWrite(const char* filename)
{
    QString tmp = filename;
    return ( this->fileWrite(tmp) );
}

Download& Download::fileWrite(const std::string& filename)
{
    QString tmp=filename.c_str();
    return ( this->fileWrite(tmp) );
}

QString* Download::getContent ()
{
    QRegExp rx("http://(.+?)/");
    QTcpSocket sock;
    QString dns;
    QString* res = new QString;
    char* buffer;
    int pos;

    if ( ( pos = rx.indexIn(this->link)) > -1)
    {
        dns = rx.cap(1);
    }
    else
    {
        InvalidUrl invalidurl;
        throw (invalidurl);
    }

    sock.connectToHost(dns, 80);
    sock.write( ("GET "+this->link+"\r\n").toAscii() );

    buffer = new char [100];
    int len;

    while ((len = sock.read(buffer, 100)) > 0)
    {
        res->append(QByteArray(buffer, len));
    }

    return res;
}
