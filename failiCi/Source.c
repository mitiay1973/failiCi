#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
	FILE* file;
	char st1[5];
	char st2[5];
	char st3[5];
	double a;
	double b;
	double c;
	file = fopen("zadacha.txt", "r");
	fgets(st1, 5, file);
	fgets(st2, 5, file);
	fgets(st3, 5, file);
	for (int i = 0; i < 5; i++)
	{
		a += st1[i];
	}
	

	fclose(file);

}