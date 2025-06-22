#include <exit_horizon.h>


void exitHorizon(int error_code)
{
    asm volatile
    (
        "movl $60, %%eax \n"
        "movl  %0, %%ebx \n"
        "syscall         \n"
        :
        : 
        "r"(error_code)
        : 
        "rax", 
        "rbx"
    );
}
