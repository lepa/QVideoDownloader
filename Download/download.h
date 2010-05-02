#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QTcpSocket>
#include <QFile>
#include <QRegExp>
#include <string>
#include <exception>


class Download
{
    QString link;
    QString cookies;
public:
    //Constructor, the optional parameter is the url that you want to download
    Download(const char* url);
    Download(const std::string& url);
    Download(const QString& url);

    //Same as setUrl
    Download& operator=(const char* url);
    Download& operator=(const std::string& url);
    Download& operator=(const QString& url);

    //Set the url for download
    Download& setUrl(const char* url);
    Download& setUrl(const std::string& url);
    Download& setUrl(const QString& url);

    //Set cookies
    Download& setCookie(const char* cookiestring);
    Download& setCookie(const std::string& cookiestring);
    Download& setCookie(const QString& cookiestring);

    //Save in a file the content of the page
    Download& fileWrite(const char* filename);
    Download& fileWrite(const std::string& filename);
    Download& fileWrite(const QString& filename);

    //Return the content of the page
    QString* getContent();
};


class InvalidUrl : public std::exception
{
    const char* what () const throw ()
    {
        return "Please check the url";
    }

};

#endif // DOWNLOAD_H
