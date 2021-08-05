#include <stdio.h>
#include <stdlib.h>
#include "mystr.h"
#pragma warning(disable:4996)

int main()
{
	// to test finding the first son string
	char t[100]; // mother string
	char p[100]; // son string
	scanf("%s", t);
	scanf("%s", p);
	int i=FindSubStr(t, p);
	printf("Location: ");
	if(i==-1) printf("not found!");
	else printf("%d",i);
    return 0;
}