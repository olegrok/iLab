#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef const int cint;
typedef const char cchar;

#define __Search_Engine_Pointer__\
            fscanf(sourse, "%s", valuestr);\
            strcpy(buf, valuestr + 1);\
            for(k = 0; k < j; k++)\
                if(strcmp(buf, points_char[k]) == 0)\
                    {\
                        fprintf(product, "%d\n", points_int[k]);\
                        break;\
                    }\
            continue;



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
    FILE *sourse = 0;
    FILE *product = 0;
    char command[15] = {}, valuestr[50] = {}, buf[50] = {};
    int i = 0, j = 0, k = 0;
    mystack_type points_int[100] = {};
    char points_char[100][100] = {};
    sourse = fopen("Source.txt","r");
    product = fopen("Product.txt","w+");


    //Считывание меток
    while(!feof(sourse))
    {
        fscanf(sourse, "%s", command);
        if(command[strlen(command) - 1] == Point)
            {
                strncpy(points_char[j], command, strlen(command) - 1);
                points_int[j] = i + 1;
                j++;

            }
        i++;
    }


    rewind(sourse);

    //Считывание команд и чисел
    while(!feof(sourse))
    {
        fscanf(sourse, "%s", command);

        if(command[strlen(command) - 1] == Point)
            {
                command[strlen(command) - 1] = 0;
                for(k = 0; k < j; k++)
                if(strcmp(command, points_char[k]) == 0)
                    {
                        fprintf(product, "%d\n", -points_int[k]);
                        break;
                    }

            }


        if(!strcmp(command, End))
            {
                fprintf(product, "%d\n", nEnd);
                fclose(sourse);
                fclose(product);
                return 0;
            }

        if(!strcmp(command, Push))
        {
            fprintf(product, "%d ", nPush);
            fscanf(sourse, "%s", valuestr);
            fprintf(product, "%s\n",valuestr);
            continue;
        }

        if(!strcmp(command, Pop))
        {
            fprintf(product, "%d\n", nPop);
            continue;
        }

        if(!strcmp(command, Add))
        {
            fprintf(product, "%d\n", nAdd);
            continue;
        }

        if(!strcmp(command, Jump))
        {
            fprintf(product, "%d ", nJump);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Mul))
          {
            fprintf(product, "%d\n", nMul);
            continue;
          }

        if(!strcmp(command, Sub))
         {
            fprintf(product, "%d\n", nSub);
            continue;
         }

        if(!strcmp(command, Div))
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
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Ret))
        {
            fprintf(product, "%d\n", nRet);
            continue;
        }

        if(!strcmp(command, Jnz))
        {
            fprintf(product, "%d ", nJnz);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Jz))
        {
            fprintf(product, "%d ", nJz);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Call))
        {
            fprintf(product, "%d ", nCall);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Cmp))
        {
            fprintf(product, "%d\n", nCmp);
            continue;
        }

        if(!strcmp(command, Je))
        {
            fprintf(product, "%d ", nJe);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Jg))
        {
            fprintf(product, "%d ", nJg);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Jl))
        {
            fprintf(product, "%d ", nJl);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Jnl))
        {
            fprintf(product, "%d ", nJnl);
            __Search_Engine_Pointer__;
        }

        if(!strcmp(command, Jng))
        {
            fprintf(product, "%d ", nJng);
            __Search_Engine_Pointer__;
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
