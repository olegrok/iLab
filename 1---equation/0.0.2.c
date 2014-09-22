#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h >
#define _ERROR {printf("Oshibka! Povtorite vvod! \n");return 0;}
typedef double dl;

dl desk(dl a, dl b, dl c)
	{
	return b*b - 4 * a*c;
	}
void resh(dl a, dl b, dl c)
{
	dl x1 = 0, x2 = 0;
	if (a != 0)
	{
		if (desk(a, b, c) >= 0)
		{
			if (desk(a, b, c) == 0)
			{
				printf("Odin koren: \n x = %g \n", -b / (2 * a));
			}
			else
			{
				x1 = (-b + desk(a, b, c)) / (2 * a);
				x2 = (-b - desk(a, b, c)) / (2 * a);
				printf("Dva kornya: \n x = %g \n x = %g \n", x1, x2);
			}
		}
		else
			printf("Kornei net\n");

	}
	else
	{
		if (b != 0)
			printf("Odin koren: \n x = %g \n", -c/b);
		else
		{
			if (c == 0)
				printf("Kornei beskonechnoe mnozhestvo\n");
			else
			printf("Kornei net\n");
		}
	}

}
void initialization(char* a, char* b, char* c)
{
        a="";
        b="";
        c="";

}

int input(char* a, char* b, char* c)
{
    int i=0;
    for(i=0;i<strlen(a);i++)
        if(!((a[i]>=48)&&(a[i]<=57)||(a[i]==46)||(a[i]==45)))
            _ERROR
    for(i=0;i<strlen(b);i++)
        if(!((b[i]>=48)&&(b[i]<=57)||(b[i]==46)||(b[i]==45)))
            _ERROR
    for(i=0;i<strlen(c);i++)
        if(!((c[i]>=48)&&(c[i]<=57)||(c[i]==46)||(c[i]==45)))
            _ERROR
    return 1;
}

void print()
{
    printf("Vvedite a,b,c cherez probel: \n");
    printf("Dlya otdeleniya drobnoj chasti ot tcenoy isplzyite \".\" \n");
    printf("\n \n");
}
int main()
	{
    const int sbl = 100;
	char a[sbl], b[sbl], c[sbl];
	dl x1 = 0, x2 = 0,kfa = 0,kfb = 0,kfc = 0;
	initialization(a,b,c);
	do
    {
        print();
        scanf("%s %s %s", &a, &b, &c);
        printf("\n");
    }
    while(input(a,b,c)==0);

        kfa = atof(a);
        kfb = atof(b);
        kfc = atof(c);

	resh(kfa, kfb, kfc);


	_getch();
	return 0;
	}
