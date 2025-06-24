#include <print.h>

/*/----------------------------------------------------------\*\

  This file implements the basic functions used to print data.

\*\----------------------------------------------------------/*/

void printString(char * string)
{
    /*/--------------------------------------------------------------------------------------\*\

      This function takes a pointer to a string as input and writes it to the standard output.

          - Inputs
          
            - name: string
              type: char *
              description: the string that we want to display.

    \*\--------------------------------------------------------------------------------------/*/
    int string_length = getStringLength(string); // Compute the string's length as we need it for the system call "write".
    if (string_length == 0) // If there is no string to print, then we simply skip the system call.
    {
        return;
    }
    asm volatile
    (
        "movq  $1, %%rax \n" // We put the value "1" in the rax to tell the system we want to use the "write" system call.
        "movq  $1, %%rdi \n" // We put the value "1" in the rdi to tell the system we want to "write" to the standard output.
        "movq  %0, %%rsi \n" // We put the first parameter "%0", here a pointer to our string in rsi to tell the system where the string we want to display starts in memory.
        "movl  %1, %%edx \n" // We put the first parameter "%1", here the size of our string in edx to tell the system what is the length of the string we want to display.
        "syscall         \n" // Executes the system call.
        :
        : // List of input operands.
        "r"(string), // The first one is the string pointer.
        "r"(string_length) // The second one the string's length.
        : // Clobbered registers that we want to reset.
        "rax", 
        "rdi",
        "rsi",
        "rdx"
    );
    // Here the instruction used for the string's length is "movl" because we are using integers which fit in 32 bits (4 bytes) and not 64 bits in which case we'd put "movq" and "rdx".
    // Similarly, the pointer has a size of 8 bytes hence the "movq" and "rsi" instead of "movl" and "edi".
    return;
}

void printInteger(int integer)
{
    /*/---------------------------------------------------------------------------\*\

      This function takes an integer as input and writes it to the standard output.
          - Inputs
            name: integer
            type: int
            description: the integer that we want to display.

    \*\---------------------------------------------------------------------------/*/
    return;
}
