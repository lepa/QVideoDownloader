#ifndef MEGAVIDEO_H
#define MEGAVIDEO_H

/*
 * Megavideo Class
 * Thanks to Bronsa
 */

#include "../vdownloader.h"
#include <exception>
#include <cstdlib>
#include <string>


class Megavideo : public vdownloader
{
protected:
    struct Data {
        QString k1;
        QString k2;
        QString final;
        QString s;
        QString un;
    } data;

    void decode ();
    void findDownLink ();
public:
    void setUrl (const QString& link);
};

class MvBadUrl
{
    const char* what() const throw()
    {
        return "Probably this is not a valid Megavideo link ";
    }
};

#endif // MEGAVIDEO_H
