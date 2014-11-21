#include "stacktitle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

    mystack_type Ax = 0;                    //Регистры
    mystack_type Bx = 0;
    mystack_type Cx = 0;
    mystack_type Dx = 0;

int proc_dump(mystack stk)
{
    printf("Registers: \n");
    printf("\tAx %d\n", Ax);
    printf("\tBx %d\n", Bx);
    printf("\tCx %d\n", Cx);
    printf("\tDx %d\n", Dx);
    stack_dump(stk);
}

int main()
{
    int sizestr = 1, size = 0, comdat = 0, j = 0, i = 0;
    mystack_type buf1 = 0, buf2 = 0, buf3 = 0;


    int* strcommand = (int*)calloc(j + 1,sizeof(int));
    FILE *product;
    assembler();
    product = fopen("Product.txt","r");


    while(!feof(product))                   //Считывание команд
    {
        fscanf(product, "%d", &strcommand[j]);
        j++;
        strcommand = (int*)realloc(strcommand, sizeof(int)*(j + 1));
    }

    fclose(product);

    mystack stk = stack_construct(1);       //Рабочий стек
    mystack call_ret = stack_construct(1);  //Стек вызова


    for(i = 0; strcommand[i]; i++)
    {
        printf("[%d] %d\n",i, strcommand[i]);
        if(strcommand[i] < 0)
            continue;
        switch (strcommand[i])
        {

            case 0: return 0;break;             //End

            case 1:                             //Push
                i++;
                stack_push(stk, strcommand[i]);
                break;

            case 2:                             //Pop
                stack_pop(stk);
                break;

            case 3:                             //Add
                stack_push(stk, stack_pop(stk) + stack_pop(stk));
                break;

            case 4:                             //Jump
                    i++;
                    i = strcommand[i] - 1;
                break;

            case 5:                             //Mul
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                stack_push(stk, buf1 * buf2);
                break;

            case 6:                             //Sub
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                stack_push(stk, buf2 - buf1);
                break;

            case 7:                             //Div
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                stack_push(stk, buf2 / buf1);
                break;
            case 8:                             //Push_Ax
                Ax = stack_top(stk);
                break;
            case 9:                             //Push_Bx
                Bx = stack_top(stk);
                break;
            case 10:                            //Push_Cx
                Cx = stack_top(stk);
                break;
            case 11:                            //Push_Dx
                Dx = stack_top(stk);
                break;
            case 12:                            //Call
                i++;
                stack_push(call_ret, i);
                i = strcommand[i] - 1;
                break;
            case 13:                            //Ret
                if(stack_check(stk) != 0)
                    i = stack_pop(call_ret);
                break;
            case 14:                            //Jnz
                i++;
                if(stack_top(stk) != 0)
                    i = strcommand[i] - 1;
                break;
            case 15:                            //Jz
                i++;
                if(stack_top(stk) == 0)
                    i = strcommand[i] - 1;
                break;

            case 16:                            //Cmp if (last > penultimate) := 1 if (last < penultimate) :=  0
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 > buf2)
                    buf3 = 1;
                if(buf1 < buf2)
                    buf3 = 0;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                stack_push(stk, buf3);
                buf3 = 0;
                break;

            case 17:                            //Je JumpIF==
                i++;
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 == buf2)
                    buf3 = 0;
                else
                    buf3 = -1;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                if(!buf3)
                    i = strcommand[i] - 1;
                buf3 = 0;
                break;

            case 18:                            //Jg last >
                i++;
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 > buf2)
                    buf3 = 0;
                else
                    buf3 = -1;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                if(!buf3)
                    i = strcommand[i] - 1;
                buf3 = 0;
                break;

            case 19:                            //Jl last <
                i++;
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 < buf2)
                    buf3 = 0;
                else
                    buf3 = -1;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                if(!buf3)
                    i = strcommand[i] - 1;
                buf3 = 0;
                break;

            case 20:                            //Jng last >=
                i++;
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 >= buf2)
                    buf3 = 0;
                else
                    buf3 = -1;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                if(!buf3)
                    i = strcommand[i] - 1;
                buf3 = 0;
                break;

            case 21:                            //Jnl jast <=
                i++;
                buf1 = stack_pop(stk);
                buf2 = stack_pop(stk);
                if(buf1 <= buf2)
                    buf3 = 0;
                else
                    buf3 = -1;
                stack_push(stk, buf2);
                stack_push(stk, buf1);
                if(!buf3)
                    i = strcommand[i] - 1;
                buf3 = 0;
                break;

            case 22:                            //Sqr
                buf1 = stack_pop(stk);
                stack_push(stk, buf1 * buf1);
                break;

            case 23:                            //Sqrt
                buf1 = stack_pop(stk);
                buf1 = (mystack_type)sqrt(buf1);
                stack_push(stk, buf1);

                break;


        }
       stack_dump(stk);

    }
    proc_dump(stk);
    stack_destruct(stk);
    stack_destruct(call_ret);
    free(strcommand);
    return 0;
}

