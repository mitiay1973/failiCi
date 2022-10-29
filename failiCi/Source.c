#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Quad(float a, float b, float c, FILE* file)
{
	float Disckiriminant, x1, x2;
	Disckiriminant = b * b - 4 * a * c;
	if ((a != 0) && (b != 0) && (c != 0))
	{
		Disckiriminant = b * b - 4 * a * c;
		if (Disckiriminant < 0)
		{
			printf("корней нет");
			fprintf(file, "Дискриминант = %f корней нет", Disckiriminant);
			fclose(file);

		}
		else if (Disckiriminant == 0)
		{
			x1 = -b / (2 * a);
			fprintf(file, "Дискриминант = %f количество корней:1 x: %f ", Disckiriminant, x1);
			fclose(file);
		}
		else if (Disckiriminant > 0)
		{
			x1 = (-b + sqrt(Disckiriminant)) / (2 * a);
			x2 = (-b - sqrt(Disckiriminant)) / (2 * a);
			printf("x1: % f x2 : % f", x1, x2);
			fprintf(file, "Дискриминант = %f количество корней:2 x1: %f x2: %f", Disckiriminant, x1, x2);
			fclose(file);
		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		printf("Корень уравнения = %f ", x1);
		fprintf(file, "Корень уравнения = %f ", x1);
		fclose(file);
	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			printf("Не имеет корней");
		}
		else
		{
			x1 = sqrt((-c / a));
			printf("Корни уравнения = %f и -%f", x1, x1);
			fprintf(file, "Корни уравнения = %f и -%f", x1, x1);
			fclose(file);
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		printf("Корни уравнения = %f и %f", x1, x2);
		fprintf(file, "Корни уравнения = %f и %f", x1, x2);
		fclose(file);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		printf("Корень уравнения = %f ", x1);
		fprintf(file, "Корнь уравнения = %f ", x1);
		fclose(file);
	}
}


void main()
{
	system("chcp 1251> nul");
	FILE* file;
	FILE* otvet = fopen("Otvet.txt", "w+");
	char line[254];
	float x1, x2;
	float a1=0, b1=0, c1=0;
	if ((file = fopen("zadacha.txt", "r")))
	{
		fgets(line, 254, file);
		/*if ((line[4] == 0) || ((line[0] < 0) || (line[2] < 0) || (line[4] < 0)))
		{
			printf("введены неполные данные или нечисловые символы ");
			return 1;
		}

		if (line[1] == 10)
		{
			a1 = line[0] - '0';

			fgets(line, 6, file);
			b1 = line[0] - '0';

			fgets(line, 6, file);
			c1 = line[0] - '0';
		}
		else
		{*/
		int cha = 0;
		double apr = 0;
		int ymna = 1;
		for (int i = 0; i < 255; i++)
		{
			if (line[i] != 32)
			{
				cha++;
			}
			else
			{
				break;
			}
		}
			for (int i = cha-1; i >= 0; i--)
			{
				if (line[i] == 46)
				{
					int chha=1;
					for (int j = 1; j < cha  - i; j++)
					{
						chha = chha * 10;
					}
					a1 = a1 / chha;
					ymna = 1;
				}
				else
				{
					if (line[0] == 45)
					{
						if (line[i] != 45)
						{
							apr = line[i] - '0';
							a1 += apr * ymna;
							ymna = ymna * 10;
						}
						else
						{
							a1 = a1 * -1;
						}
					}
					else
					{
						apr = line[i] - '0';
						a1 += apr * ymna;
						ymna = ymna * 10;
					}
				}
				}

			int chb = cha;
			double bpr = 0;
			int ymnb = 1;
			for (int i = cha+1; i < 255; i++)
			{
				if (line[i] != 32)
				{
					chb++;
				}
				else
				{
					break;
				}
			}
			for (int i = chb; i >= cha+1; i--)
			{
				if (line[i] == 46)
				{
					int chhb = 1;
					for (int j = 1; j < chb+1 - i; j++)
					{
						chhb = chhb * 10;
					}
					b1 = b1 / chhb;
					ymnb = 1;
				}
				else
				{
					if (line[cha + 1] == 45)
					{
						if (line[i] != 45)
						{
							bpr = line[i] - '0';
							b1 += bpr * ymnb;
							ymnb = ymnb * 10;
						}
						else
						{
							b1 = b1 * -1;
						}
					}
					else
					{
						bpr = line[i] - '0';
						b1 += bpr * ymnb;
						ymnb = ymnb * 10;
					}
				}
			}
			int chc = chb;
			double cpr = 0;
			int ymnc = 1;
			for (int i = chb + 2; i < 255; i++)
			{
				if (line[i] != -52)
				{
					chc++;
				}
				else
				{
					break;
				}
			}
			for (int i = chc; i >= chb + 2; i--)
			{
				if (line[i] == 46)
				{
					int chhc = 1;
					for (int j = 1; j < chc + 1 - i; j++)
					{
						chhc = chhc * 10;
					}
					c1 = c1 / chhc;
					ymnc = 1;
				}
				else
				{
					if (line[chb + 2] == 45)
					{
						if (line[i] != 45)
						{
							cpr = line[i] - '0';
							c1 += cpr * ymnc;
							ymnc = ymnc * 10;
						}
						else
						{
							c1 = c1 * -1;
						}
					}
					else
					{
						cpr = line[i] - '0';
						c1 += cpr * ymnc;
						ymnc = ymnc * 10;
					}
				}
			}
		}
		Quad(a1, b1, c1, otvet);
	}
//}