#include <print.h>

/*/---------------------------------------------------------\*\

  This file implements the main function used in the program.

\*\---------------------------------------------------------/*/

void testPrint()
{
  /*/------------------------------------------------------------\*\

    This function takes no input and tests the printing functions.

  \*\------------------------------------------------------------/*/
  printString("This is a test, LOL!\n");
  printInteger(0);
  printString("\n");
  printInteger(-5);
  printString("\n");
  printInteger(5);
  printString("\n");
  printInteger(-51092);
  printString("\n");
  printInteger(51092);
  printString("\n");
  printInteger(9223372036854775807);
  printString("\n");
  printInteger(LONG_MIN);
  printString("\n");
  printInteger(-9223372036854775807);
  printString("\n");
  return;
}

int main()
{
  /*/------------------------------------------------------------------------------------------------------\*\

    This function takes no input and returns a potential error code. It is used to handle the program logic.

        - Outputs
          type: int
          description: the desired error code. 0 represents no error, everything else represents an error.

  \*\------------------------------------------------------------------------------------------------------/*/
  testPrint();
  return 0;
}
