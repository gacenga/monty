#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
* main - main function
*
* @argc:argument count
* @argv:pointer to arguments
* Return:int
*/
int main(int argc, char *argv[])
{
char opcode[256];
int value;
unsigned int line_number = 0;
FILE *file;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file");
return (EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
while (fscanf(file, "%s", opcode) == 1)
{
line_number++;
if (strcmp(opcode, "push") == 0)
{
if (fscanf(file, "%d", &value) != 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(file);
return (EXIT_FAILURE);
}
push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack, line_number);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
fclose(file);
return (EXIT_FAILURE);
}
}
fclose(file);
return (EXIT_SUCCESS);
}
