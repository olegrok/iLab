#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

const int nEnd = 0;
const int nPush = 1;
const int nPop = 2;
const int nAdd = 3;
const int nJump = 4;
const int nMul = 5;
const int nSub = 6;
const int nDiv = 7;

const char End[4] = "end";
const char Push[5] = "push";
const char Pop[4] = "pop";
const char Add[4] = "add";
const char Jump[5] = "jump";
const char Mul[4] = "mul";
const char Sub[4] = "sub";
const char Div[4] = "div";


void assembler()
{
    FILE *sourse;
    FILE *product;
    char command[15], valuestr[15];
    sourse = fopen("Source.txt","r");
    product = fopen("Product.txt","w+");
    while(!feof(sourse))
    {
        fscanf(sourse, "%s", command);

        if(strcmp(command, End) == 0)
            {
                fprintf(product, "%d\n", nEnd);
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
            fprintf(product, "%s\n",valuestr);
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
    }

    fprintf(product, "%s", "\0");
    fclose(sourse);
    fclose(product);
}
void disassembler()
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

