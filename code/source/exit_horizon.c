#include <exit_horizon.h>

/*/---------------------------------------------------------------\*\

  This file implements the basic function used to exit the program.

\*\---------------------------------------------------------------/*/

void exitHorizon(int error_code)
{
    /*/------------------------------------------------------------------------\*\

      This function takes an error code as input and exit the program with it.

          - Inputs
          
            - name: error_code
              type: int
              description: the error code that we want to use to exit the program.

    \*\------------------------------------------------------------------------/*/
    asm volatile
    (
        "movq $60, %%rax \n" // We put the value "60" in the rax to tell the system we want to use the "exit" system call.
        "movl  %0, %%ebx \n" // We put the first parameter "%0", here a pointer to our string in rsi to tell the system where the string we want to display starts in memory.
        "syscall         \n"
        :
        : // List of input operands.
        "r"(error_code) // The first one is the error code we want to return.
        : // Clobbered registers that we want to reset.
        "rax",
        "rbx"
    );
    // Here the instruction used for the error code is "movl" because we are using integers which fit in 32 bits (4 bytes) and not 64 bits in which case we'd put "movq" and "rdx".
}
