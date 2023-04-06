#include "main.h"
#include <stdio.h>
/**
 * _print_rev_recursion - print a string
 * @s:string
 * Return:void
 */
void _print_rev_recursion(char *s)
{
if (*s)
{
	print_rev_recursion(s + 1);
		putchar(*s);

}
}
