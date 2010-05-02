#ifndef YOUPORN_H
#define YOUPORN_H

#include "../vdownloader.h"
#include <exception>

class Youporn : public vdownloader
{
private:
    void findDownLink ();
};


class YpBadUrl : public std::exception
{
    const char* what () const throw()
    {
        return "Probably this is not a valid Youporn url";
    }
};

#endif // YOUPORN_H
