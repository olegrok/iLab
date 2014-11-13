#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef const int cint;
typedef const char cchar;

cint nEnd =     0;
cint nPush =    1;
cint nPop =     2;
cint nAdd =     3;
cint nJump =    4;
cint nMul =     5;
cint nSub =     6;
cint nDiv =     7;
cint nPushAx =  8;
cint nPushBx =  9;
cint nPushCx =  10;
cint nPushDx =  11;
cint nCall =    12;
cint nRet =     13;
cint nJnz =     14;
cint nJz =      15;
cint nCmp =     16;
cint nJe =      17;
cint nJg =      18;
cint nJl =      19;
cint nJng =     20;
cint nJnl =     21;
cint nSqr =     22;
cint nSqrt =    23;


cchar Point =       ':';
cchar End[4] =      "end";
cchar Push[5] =     "push";
cchar Pop[4] =      "pop";
cchar Add[4] =      "add";
cchar Jump[5] =     "jump";
cchar Mul[4] =      "mul";
cchar Sub[4] =      "sub";
cchar Div[4] =      "div";
cchar PushAx[8] =   "push_ax";
cchar PushBx[8] =   "push_bx";
cchar PushCx[8] =   "push_cx";
cchar PushDx[8] =   "push_dx";
cchar Call[5] =     "call";
cchar Ret[4] =      "ret";
cchar Jnz[4] =      "jnz";
cchar Jz[3] =       "jz";
cchar Cmp[4] =      "cmp";
cchar Je[3] =       "je";
cchar Jg[3] =       "jg";
cchar Jl[3] =       "jl";
cchar Jng[4] =      "jng";
cchar Jnl[4] =      "jnl";
cchar Sqr[4] =      "sqr";
cchar Sqrt[5] =     "sqrt";


int assembler()
{
    FILE *sourse;
    FILE *product;
    char command[15], valuestr[50], buf[50];
    int points_int[100], i = 0, j = 0, k = 0;
    char points_char[100][100];
    sourse = fopen("Source.txt","r");
    product = fopen("Product.txt","w+");

    while(!feof(sourse))
    {
        fscanf(sourse, "%s", command);
        if(command[strlen(command) - 1] == Point)
            {
                strncpy(points_char[j], command, strlen(command) - 1);
                points_int[j] = i + 1;
                printf("j: %d   i: %d  com: %s  \n", j, points_int[j], points_char[j]);
                j++;

            }
        i++;
    }


    rewind(sourse);

    while(!feof(sourse))
    {
        fscanf(sourse, "%s", command);
        printf("%s \n", command);

        if(command[strlen(command) - 1] == Point)
            {
                command[strlen(command) - 1] = 0;
                printf("com: %s  \n", command);
                for(k = 0; k < j; k++)
                if(strcmp(command, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", -points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            }


        if(strcmp(command, End) == 0)
            {
                fprintf(product, "%d\n", nEnd);
                fclose(sourse);
                fclose(product);
                return 0;
            }

        if(strcmp(command, Push) == 0)
        {
            fprintf(product, "%d ", nPush);
            fscanf(sourse, "%s", valuestr);
            fprintf(product, "%s\n",valuestr);
            continue;
        }

        if(strcmp(command, Pop) == 0)
        {
            fprintf(product, "%d\n", nPop);
            continue;
        }

        if(strcmp(command, Add) == 0)
        {
            fprintf(product, "%d\n", nAdd);
            continue;
        }

        if(strcmp(command, Jump) == 0)
        {
            fprintf(product, "%d ", nJump);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        //printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(strcmp(command, Mul) == 0)
          {
            fprintf(product, "%d\n", nMul);
            continue;
          }

        if(strcmp(command, Sub) == 0)
         {
            fprintf(product, "%d\n", nSub);
            continue;
         }

        if(strcmp(command, Div) == 0)
        {
            fprintf(product, "%d\n", nDiv);
            continue;
        }

        if(!strcmp(command, PushAx))
        {
            fprintf(product, "%d\n", nPushAx);
            continue;
        }

        if(!strcmp(command, PushBx))
        {
            fprintf(product, "%d\n", nPushBx);
            continue;
        }

        if(!strcmp(command, PushCx))
        {
            fprintf(product, "%d\n", nPushCx);
            continue;
        }

        if(!strcmp(command, PushDx))
        {
            fprintf(product, "%d\n", nPushDx);
            continue;
        }

        if(!strcmp(command, Call))
        {
            fprintf(product, "%d ", nCall);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Ret))
        {
            fprintf(product, "%d\n", nRet);
            continue;
        }

        if(!strcmp(command, Jnz))
        {
            fprintf(product, "%d ", nJnz);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d \n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Jz))
        {
            fprintf(product, "%d ", nJz);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Call))
        {
            fprintf(product, "%d ", nCall);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Cmp))
        {
            fprintf(product, "%d\n", nCmp);
            continue;
        }

        if(!strcmp(command, Je))
        {
            fprintf(product, "%d ", nJe);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Jg))
        {
            fprintf(product, "%d ", nJg);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Jl))
        {
            fprintf(product, "%d ", nJl);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Jnl))
        {
            fprintf(product, "%d ", nJnl);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Jng))
        {
            fprintf(product, "%d ", nJng);
            fscanf(sourse, "%s", valuestr);
            strcpy(buf, valuestr + 1);
            for(k = 0; k < j; k++)
                if(strcmp(buf, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", points_int[k]);
                        printf("char: %s int: %d \n", points_char[k], points_int[k]);
                        break;
                    }

            continue;
        }

        if(!strcmp(command, Sqr))
        {
            fprintf(product, "%d\n", nSqr);
            continue;
        }

        if(!strcmp(command, Sqrt))
        {
            fprintf(product, "%d\n", nSqrt);
            continue;
        }
















    }

    fprintf(product, "%s", "\0");
    fclose(sourse);
    fclose(product);
}
int disassembler()
{
    FILE *sourseimage;
    FILE *product;
    int command;
    char valuestr[15];
    product = fopen("Product.txt","r");
    sourseimage = fopen("Sourseimage.txt","w+");
    while(!feof(product))
    {
        fscanf(product, "%d", &command);
        switch (command)
        {
            case 0:
                fprintf(sourseimage, "%s\n", End);
                fclose(sourseimage);
                fclose(product);
                return 0;
                break;
            case 1:
                fprintf(sourseimage, "%s ", Push);
                fscanf(product, "%s", valuestr);
                fprintf(sourseimage, "%s\n", valuestr);
                break;
            case 2:
                fprintf(sourseimage, "%s\n", Pop);
                break;
            case 3:
                fprintf(sourseimage, "%s\n", Add);
                break;
            case 4:
                fprintf(sourseimage, "%s ", Jump);
                fscanf(product, "%s", valuestr);
                fprintf(sourseimage, "%s\n", valuestr);
                break;
            case 5:
                fprintf(sourseimage, "%s\n", Mul);
                break;
            case 6:
                fprintf(sourseimage, "%s\n", Sub);
                break;
            case 7:
                fprintf(sourseimage, "%s\n", Div);
                break;
        }
    }

    fclose(sourseimage);
    fclose(product);
}
