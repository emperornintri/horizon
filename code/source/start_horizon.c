#include <exit_horizon.h>

/*/----------------------------------------------------------------\*\

  This file implements the basic function used to start the program.

\*\----------------------------------------------------------------/*/

extern int main(); // Defines the main function as one from outside this file and outside of exit_horizon.h.    


void startHorizon()
{
    /*/---------------------------------------------------------------------------------------------------------\*\

      This function takes no input nor does it return an output. It is used as the starting point of the program.

    \*\---------------------------------------------------------------------------------------------------------/*/
    int result = main(); // This line executes the main function and store a potential error code.
    exitHorizon(result); // The error code is used to exit the program.
}
