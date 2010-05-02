#include "vdownloader.h"


void vdownloader::operator ()(const char* link)
{
    this->watchLink = link;
    this->findDownLink();
}

void vdownloader::operator ()(const QString& link)
{
    this->watchLink = link;
    this->findDownLink();
}

void vdownloader::operator ()(const std::string& link)
{
    this->watchLink = link.c_str();
    this->findDownLink();
}

void vdownloader::setUrl(const char* link)
{
    this->watchLink = link;
    this->findDownLink();
}

void vdownloader::setUrl(const QString& link)
{
    this->watchLink = link;
    this->findDownLink();
}

void vdownloader::setUrl(const std::string& link)
{
    this->watchLink = link.c_str();
    this->findDownLink();
}

const char* vdownloader::getDownLink()
{
    return this->downLink.toAscii().constData();
}
