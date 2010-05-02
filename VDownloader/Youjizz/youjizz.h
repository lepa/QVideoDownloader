#ifndef YOUJIZZ_H
#define YOUJIZZ_H

#include "../vdownloader.h"
#include <exception>

class Youjizz : public vdownloader
{
protected:
    void findDownLink ();
};

class YjBadUrl
{
    const char* what() const throw()
    {
        return "Probably this is not a valid Youjizz link ";
    }
};

#endif // YOUJIZZ_H
