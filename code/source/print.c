#include <print.h>


void printString(char * string)
{
    int string_length = getStringLength(string);
    asm volatile
    (
        "movq  $1, %%rax \n"
        "movq  $1, %%rdi \n"
        "movq  %0, %%rsi \n"
        "movl  %1, %%edx \n"
        "syscall         \n"
        :
        : 
        "r"(string), "r"(string_length)
        : 
        "rax", 
        "rdi",
        "rsi",
        "rdx"
    );
}

void printInteger(int integer)
{
}
