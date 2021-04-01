#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = wildcmp("main.c", "*.c");
	printf("%d\n", r);
	r = wildcmp("main.c", "m*a*i*n*.*c*");
	printf("%d\n", r);
	r = wildcmp("main.c", "main.c");
	printf("%d\n", r);
	r = wildcmp("main.c", "m*c");
	printf("%d\n", r);
	r = wildcmp("main.c", "ma********************************c");
	printf("%d\n", r);
	r = wildcmp("main.c", "*");
	printf("%d\n", r);
	r = wildcmp("main.c", "***");
	printf("%d\n", r);
	r = wildcmp("main.c", "m.*c");
	printf("%d\n", r);
	r = wildcmp("main.c", "**.*c");
	printf("%d\n", r);
	r = wildcmp("main-main.c", "ma*in.c");
	printf("%d\n", r);
	r = wildcmp("main", "main*d");
	printf("%d\n", r);
	r = wildcmp("abc", "*b");
	printf("%d\n", r);

	printf("------------------------\n");

	r = wildcmp("maintain", "m*a*i*n*");
	printf("%d\n", r);
	r = wildcmp("maintain", "m*n");
	printf("%d\n", r);
	r = wildcmp("maintain", "m*n*n");
	printf("%d\n", r);
	r = wildcmp("main", "m*n");
	printf("%d\n", r);
	r = wildcmp("main", "m*n*n"); /* Should NOT match. */
	printf("%d\n", r);
	r = wildcmp("m1aintain", "m*a*i*n*");
	printf("%d\n", r);
	r = wildcmp("maintain", "m1*a*i*n*"); /* Should NOT match. */
	printf("%d\n", r);

	printf("------------------------\n");

	r = wildcmp("", "*"); /* Should match. */
	printf("%d\n", r);
	r = wildcmp(" ", "*"); /* Should match. */
	printf("%d\n", r);
	r = wildcmp(" ", "*"); /* Should match. */
	printf("%d\n", r);
	r = wildcmp("", ""); /* Should match. */
	printf("%d\n", r);
	r = wildcmp("", " "); /* Should NOT match. */
	printf("%d\n", r);
	r = wildcmp(" ", ""); /* Should NOT match. */
	printf("%d\n", r);
	r = wildcmp(" ", " "); /* Should match. */
	printf("%d\n", r);
	r = wildcmp("", " *"); /* Should NOT match. */
	printf("%d\n", r);

	printf("------------------------\n");

	r = wildcmp("main", "main"); /* Should match. */
	printf("%d\n", r);
	r = wildcmp("main", "MAIN"); /* Should match. */
	printf("%d\n", r);

	return (0);
}
