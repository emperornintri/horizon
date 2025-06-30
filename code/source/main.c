#include <memory.h>
#include <print.h>

/*/---------------------------------------------------------\*\

  This file implements the main function used in the program.

\*\---------------------------------------------------------/*/

void testMemory()
{
  /*/----------------------------------------------------------\*\

    This function takes no input and tests the memory functions.

  \*\----------------------------------------------------------/*/
  IntegerVector vector;
  vector.length = 10;
  vector.pointer = memoryMap(0, sizeof(int) * vector.length, PROTECTION_READ | PROTECTION_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  vector.pointer[0] = 0;
  vector.pointer[1] = 1;
  vector.pointer[2] = 2;
  vector.pointer[3] = 3;
  vector.pointer[4] = 4;
  vector.pointer[5] = 5;
  printIntegerVector(vector);
  return;
}

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
  testMemory();
  // testPrint();
  return 0;
}
