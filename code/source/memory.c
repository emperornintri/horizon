#include <memory.h>

/*/---------------------------------------------------------------\*\

  This file implements the basic function used to exit the program.

\*\---------------------------------------------------------------/*/

void * memoryMap(void * address, unsigned long length, unsigned long protection, unsigned long flags, unsigned long file_descriptor, unsigned long offset)
{
  /*/-----------------------------------------------------------------------------------------------------------------------------------------------------\*\

    This function is used to map the memory of a file to the memory of the program.

        - Inputs

          - name: address
            type: void * 
            description: the address giving a hint as to where the resulting pointer should be stored.

          - name: length
            type: unsigned long
            description: the amount of bytes we want to be able to store in our mapped memory.

          - name: protection
            type: unsigned long
            description: the desired protection of our mapped memory. The value has to be decided by OR'ing the defined values (PROTECTION_*) in memory.h.

          - name: flags
            type: unsigned long
            description: the desired visibility of our mapped memory. The value has to be decided by picking one of the defined values (MAP_*) in memory.h.

          - name: file_descriptor
            type: unsigned long
            description: the file descriptor to which the memory should be mapped.

          - name: offset
            type: unsigned long
            description: the offset to use in the mapping a.k.a the shift considered to start mapping the file's content.

  \*\-----------------------------------------------------------------------------------------------------------------------------------------------------/*/
  void * pointer;
  asm volatile
  (
      "movq $9, %%rax \n" // We put the value "9" in the rax to tell the system we want to use the "mmap" system call.
      "movq %1, %%rdi \n"
      "movq %2, %%rsi \n"
      "movq %3, %%rdx \n"
      "movq %4, %%r10 \n"
      "movq %5,  %%r8 \n"
      "movq %6,  %%r9 \n"
      "syscall        \n"
      "movq %%rax, %0 \n"
      : // List of output operands.
      "=r"(pointer)
      :// List of input operands.
      "r"(address),
      "r"(length),
      "r"(protection),
      "r"(flags),
      "r"(file_descriptor),
      "r"(offset)
      : // Clobbered registers that we want to reset.
      "rax", 
      "rdi",
      "rsi",
      "rdx",
      "r10",
        "r8",
        "r9"
  );
  return pointer;
}

int memoryUnmap(void * address, unsigned long length)
{
  /*/-----------------------------------------------------------------------------------------------------------------------------------------------------\*\

    This function is used to unmap the memory of a file to the memory of the program.

        - Inputs

          - name: address
            type: void * 
            description: the address of the memory we want to unmap.

          - name: length
            type: unsigned long
            description: the amount of bytes we want to unmap from our memory.

        - Outputs
          type: int
          description: the error code of the operation.

  \*\-----------------------------------------------------------------------------------------------------------------------------------------------------/*/
  asm volatile
  (
      "movq $11, %%rax \n" // We put the value "9" in the rax to tell the system we want to use the "mmap" system call.
      "movq  %0, %%rdi \n"
      "movq  %1, %%rsi \n"
      "syscall         \n"
      :
      :// List of input operands.
      "r"(address),
      "r"(length)
      : // Clobbered registers that we want to reset.
      "rax", 
      "rdi",
      "rsi"
  );
}
