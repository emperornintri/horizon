#ifndef MEMORY_H
#define MEMORY_H

/*/---------------------------------------------------------------------------------\*\

  This file defines the basic constants and functions used to manage the memory inside the program.

\*\---------------------------------------------------------------------------------/*/

#define MAP_SHARED        0x1 // Share the mapped memory.
#define MAP_PRIVATE       0x2 // Keep the mapped memory private.

#define MAP_ANONYMOUS    0x20 // The mapping is not related to any files. Initialize to 0.

#define PROTECTION_READ   0x1 // The allocated page can be read.
#define PROTECTION_WRITE  0x2 // The allocated page can be written.
#define PROTECTION_EXEC   0x4 // The allocated page can be executed.
#define PROTECTION_NONE   0x0 // The allocated page can not be accessed.

void * memoryMap(void * address, unsigned long length, unsigned long protection, unsigned long flags, unsigned long file_descriptor, unsigned long offset);

#endif
