#include <stdio.h>
#include <strings.h>

int main()
{
	printf("\n[%d]\n", strcasecmp("Mateus", "mateus"));
	printf("\n[%d]\n", strcasecmp("Lucas", "mateus"));
	printf("\n[%d]\n", strcasecmp("Mateus", "lucas"));
	return 0;
}