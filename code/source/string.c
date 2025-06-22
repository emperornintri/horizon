#include <string.h>


 
//!\\ Single line comment.

/*/-----------------\*\
|                     |
| This is an example. |
|                     |
\*\-----------------/*/


int getStringLength(char * string)
{
    if (string[0] == '\0')
    {
        return 0;
    }
    int length = 1;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}
                                                                                                   