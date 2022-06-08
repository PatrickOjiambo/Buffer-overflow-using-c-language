#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
 int value = 5;
 char buffer_one[8], buffer_two[8];
 strcpy(buffer_one, "one"); /* Put "one" into buffer_one. */
 strcpy(buffer_two, "two"); /* Put "two" into buffer_two. */
 printf("[BEFORE] buffer_two is at %p and contains \'%s\'\n", buffer_two, buffer_two);
 printf("[BEFORE] buffer_one is at %p and contains \'%s\'\n", buffer_one, buffer_one);
 printf("[BEFORE] value is at %p and is %d (0x%08x)\n", &value, value, value);
 printf("\n[STRCPY] copying %d bytes into buffer_two\n\n", strlen(argv[1]));
 strcpy(buffer_two, argv[1]); /* Copy first argument into buffer_two. */
 printf("[AFTER] buffer_two is at %p and contains \'%s\'\n", buffer_two, buffer_two);
 printf("[AFTER] buffer_one is at %p and contains \'%s\'\n", buffer_one, buffer_one);
 printf("[AFTER] value is at %p and is %d (0x%08x)\n", &value, value, value);
}
/*--By now, you should be able to read the source code above and figure out
what the program does. After compilation in the sample output below, we try
to copy ten bytes from the first command-line argument into buffer_two, which
only has eight bytes allocated for it.
--Notice that buffer_one is located directly after buffer_two in memory, so
when ten bytes are copied into buffer_two, the last two bytes of 90 overflow
into buffer_one and overwrite whatever was there.
A larger buffer will naturally overflow into the other variables, but if a large
enough buffer is used, the program will crash and die.
---
These types of program crashes are fairly common—think of all of the
times a program has crashed or blue-screened on you. The programmer’s
mistake is one of omission—there should be a length check or restriction on
the user-supplied input. These kinds of mistakes are easy to make and can be
difficult to spot. Program crashes are annoying, but in the hands of a hacker they can
become downright dangerous. A knowledgeable hacker can take control of a
program as it crashes, with some surprising results. My next code on exploit_notesearch.c demonstrates how program crash can be advantageous to a hacker.*/
