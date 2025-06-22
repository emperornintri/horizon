#include <string.h>

/*/-------------------------------------------------------------------------------\*\

  This file implements the basic functions that are useful for string manipulation.

\*\-------------------------------------------------------------------------------/*/

int getStringLength(char * string)
{
    /*/--------------------------------------------------------------------------------------------------\*\

      This function takes a pointer to a string as input and returns the size of the corresponding string.
          - Inputs
            name: string
            type: char *
            description: the string for which we want to compute the length.
          - Outputs
            type: int
            description: the length of the input string.

    \*\--------------------------------------------------------------------------------------------------/*/
    if ((string == ((void *)0)) || (string[0] == '\0')) // Check if the pointer is null or if it has size 0.
    {
        return 0;
    }
    int length = 1; 
    while (string[length] != '\0') // If the pointer is not null and has a size greater than 0, we loop until we find the end character '\0'.
    {
        length++;
    }
    return length;
}
                                                                                                   