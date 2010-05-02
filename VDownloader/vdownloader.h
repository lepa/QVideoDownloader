#ifndef VDOWNLOADER_H
#define VDOWNLOADER_H

#include "../Download/download.h"

class vdownloader
{
protected:
   QString watchLink;
   QString downLink;
   virtual void findDownLink () = 0;
public:
   virtual void operator() (const char* link);
   virtual void operator() (const QString& link);
   virtual void operator() (const std::string& link);

   virtual void setUrl (const char* link);
   virtual void setUrl (const QString& link);
   virtual void setUrl (const std::string& link);

   virtual const char* getDownLink ();
};

#endif // VDOWNLOADER_H
