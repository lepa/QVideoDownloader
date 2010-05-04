#include "download.h"
#include <iostream>

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

Download& Download::setCookie(const std::string& cookiestring)
{
    this->cookies = cookiestring.c_str();
    return *this;
}

Download& Download::fileWrite(const QString& filename)
{
    QRegExp rx("http://([^/]+)(/.+)$", Qt::CaseSensitive, QRegExp::RegExp2);
    QTcpSocket sock;
    QString dns, page;
    QFile* file;
    char* buffer;
    int pos;

    if ( ( pos = rx.indexIn(this->link)) > -1)
    {
        dns = rx.cap(1);
        page = rx.cap(2);
    }
    else
    {
        throw *(new InvalidUrl);
    }

    sock.connectToHost(dns, 80);
    sock.write( ("GET "+page+"Host: "+dns+"\n"+this->cookies+"\n\n").toAscii() );

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
    QRegExp rx("http://([^/]+)(/.+)$", Qt::CaseSensitive, QRegExp::RegExp2);
    QTcpSocket sock;
    QString dns, page;
    QString* res = new QString;
    char* buffer;
    int pos;

    if ( ( pos = rx.indexIn(this->link)) != -1)
    {
        dns = rx.cap(1);
        page = rx.cap(2);
    }
    else
    {
        InvalidUrl invalidurl;
        throw (invalidurl);
    }

    sock.connectToHost(dns, 80);
	
    sock.write( ("GET "+page+"\nHost:"+dns+"\n"+this->cookies+"\n\n").toAscii() );

    buffer = new char [100];
    int len;

    while ((len = sock.read(buffer, 100)) > 0)
    {
		QByteArray b(buffer, len);
        res->append(b);
    }
	std::cout << res->toStdString() << std::endl;

    return res;
}
