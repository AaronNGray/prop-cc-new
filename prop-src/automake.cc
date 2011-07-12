#include <ctime>
#include <sys/stat.h>
//#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include "basics.h"

Bool out_of_date (const char * filename, struct stat& target)
{
   struct stat source; 
   if (stat(filename, &source)) 
   {  perror(filename); return true; }
   double d = std::difftime(source.st_mtime,target.st_mtime);
   return d > 0.0;
}
