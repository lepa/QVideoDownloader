#ifndef YOUTUBE_H
#define YOUTUBE_H

#include "../vdownloader.h"
#include <exception>


class Youtube : public vdownloader
{
protected:
    void findDownLink();
};

class YtBadUrl : public std::exception
{
    const char* what() const throw()
    {
        return "Probably this is not a valid youtube link";
    }
};

#endif // YOUTUBE_H
