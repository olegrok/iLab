/*Решение квадратного уравнения © Бабин Олег*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h >
#include <math.h>
#define _ERROR {printf("Oshibka! Povtorite vvod! \n");return -1;}
typedef double dl;

dl desk(dl a, dl b, dl c) // Дискриминант. Переменные - коэффициенты.
	{
	return b * b - 4 * a * c;
	}
void resh(dl a, dl b, dl c) // Решение уравнения. Переменные коэффициенты. ч1 и x2 - решения.
{
	dl x1 = 0, x2 = 0;
	if (a != 0)
	{
		if (desk(a, b, c) >= 0)
		{
			if (desk(a, b, c) == 0)
			{
				printf("Odin koren: \n x = %g \n", -b / (2 * a) + 0.0);
			}
			else
			{
				x1 = (-b + sqrt(desk(a, b, c))) / (2 * a);
				x2 = (-b - sqrt(desk(a, b, c))) / (2 * a);
				printf("Dva kornya: \n x = %g \n x = %g \n", x1, x2);
			}
		}
		else
			printf("Kornei net\n");

	}
	else
	{
		if (b != 0)
			{
			    printf("Odin koren: \n x = %g \n", - c / b + 0.0);
			}
		else
		{
			if (c == 0)
				printf("Kornei beskonechnoe mnozhestvo\n");
			else
			printf("Kornei net\n");
		}
	}

}
int input(char* const a, char* const b, char* const c) // Проверка вводимых данных на правильность
{
    int i = 0;
    for(i = 0;i < strlen(a);i++)
        if(!((48 <= a[i]) && (a[i] <= 57)||(a[i] == 46) || (a[i] == 45)))
            _ERROR //{printf("Oshibka! Povtorite vvod! \n");return -1;}
    for(i=0;i<strlen(b);i++)
        if(!((48 <= b[i]) && (b[i] <= 57)||(b[i] == 46) || (b[i] == 45)))
            _ERROR
    for(i=0;i<strlen(c);i++)
        if(!((48 <= c[i]) && (c[i] <= 57)||(c[i] == 46) || (c[i] == 45)))
            _ERROR
    return 0;
}

void print() //Вывод сообщений, призывающих ввести данные
{
    printf("Vvedite a,b,c cherez probel: \n");
    printf("Dlya otdeleniya drobnoj chasti ot tcenoy isplzyite \".\" \n");
    printf("\n \n");
}
int main()
	{
    const int sbl = 100;//Размер массива - максимальное колицество цифр и знаков в вводимом числе
	char a[sbl], b[sbl], c[sbl];
	dl kfa = 0,kfb = 0,kfc = 0; //Коэффициенты
	do
    {
        print();
        scanf("%s %s %s", a, b, c);
        printf("\n");
    }
    while(input(a,b,c)==-1);

        kfa = atof(a);
        kfb = atof(b);
        kfc = atof(c);

	resh(kfa, kfb, kfc);


	_getch();
	return 0;
	}
