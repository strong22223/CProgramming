#include<stdio.h>
#include<string.h>
int main()


{
	char ap[10] = { "aaaaaaaa" };
	char c[10] = { "mmm" };
	strncpy_s(ap+1, strlen(c), c, strlen(c));
	for (int i = 0; i < 8; i++)
		putchar(ap[i]);
	printf("\n\n");
	puts(ap);
	return 0;
}