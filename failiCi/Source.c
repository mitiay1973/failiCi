#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Quad(float a, float b, float c, FILE* file)
{
	float Disckiriminant, x1, x2;
	Disckiriminant = b * b - 4 * a * c;
	if (Disckiriminant < 0)
	{
		fprintf(file, "Дискриминанта нет");
	}
	if (Disckiriminant == 0)
	{
		x1 = (-b) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", Disckiriminant);
		fprintf(file, "x1 = %f", x1);
	}
	if (Disckiriminant > 0)
	{
		x1 = ((-b) - sqrt(Disckiriminant)) / (2 * a);
		x2 = ((-b) + sqrt(Disckiriminant)) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", Disckiriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1, x2);
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
				if (line[cha+1] == 45)
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
		Quad(a1, b1, c1, otvet);
	}
//}