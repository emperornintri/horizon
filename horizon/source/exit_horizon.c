void exitHorizon (int status)
{
    asm volatile 
    (
      "movq $60, %%rax\n"
      "movl  %0, %%edi\n"
      "syscall        \n"
      :
      : 
      "r"(status)
      : 
      "rax", "rdi", "rcx", "r11"
    );
}