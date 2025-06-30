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

void printInteger(long int integer)
{
    /*/---------------------------------------------------------------------------\*\

      This function takes an integer as input and writes it to the standard output.
          - Inputs
            name: integer
            type: int
            description: the integer that we want to display.

    \*\---------------------------------------------------------------------------/*/
    if (integer == 0) // Special case, the integer is 0, we print 0 directly.
    {
      printString("0");
      return;
    }
    if (integer == LONG_MIN) // Another special case, the integer is the minimum possible value.
    {
      printString("-9223372036854775808"); // This is important because 9223372036854775808 doesn't fit inside a long int so it would glitch afterward.
      return;
    }
    char integer_as_string[21]; // 21 because in the "worse" case scenario, -9223372036854775808 is 20 characters long. You need one more for '\0'.
    int index = 0; // Used to know where to start filling the digits depending of the positivity of your integer.
    if (integer < 0)
    {
      integer_as_string[0] = '-'; // If negative, the first character is '-' and we start filling at the first position.
      index = 1;
      integer = -integer; // And then we consider the absolute value of the integer.
    }
    int current_power = 0; // The main loop is explained in the DOCUMENTATION.pdf.
    while (integer / 10 > 0) // We fill the string from the right (because we do not know the length of the interger in advance).
    {
      integer_as_string[19 - current_power] = '0' + integer - 10 * (integer / 10); // To convert a digit so string we use the trick '0' + digit.
      current_power++;
      integer /= 10;
    }
    integer_as_string[19 - current_power] = '0' + integer; // Last quotient to consider.
    for (int i = 0; i <= current_power; i++) // We move the digits back to the first positions now that the main loop is finished.
    {
      integer_as_string[index + i] = integer_as_string[19 - current_power + i];
    }
    integer_as_string[index + current_power + 1] = '\0';
    printString(integer_as_string);
    return;
}

void printIntegerVector(IntegerVector vector)
{
  printString("[");
  for (int index = 0; index < vector.length - 1; index++)
  {
    printInteger(vector.pointer[index]);
    printString(", ");
  }
  printInteger(vector.pointer[vector.length - 1]);
  printString("]\n");  
  return;
}
