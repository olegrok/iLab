/*
Babin Oleg

Control work 2007
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
typedef unsigned int uint;
typedef unsigned long long ull;
uint nok(uint Num1, uint Num2) //Least Common Multiple
{
unsigned int buf1, SaveNumb2, SaveNumb1;
    SaveNumb2 = Num2; SaveNumb1 = Num1;
  while(Num1 % Num2 != 0)
  {
      buf1 = Num1 % Num2;
      Num1 = Num2;
      Num2 = buf1;
  }
  return ((SaveNumb1*SaveNumb2)/Num2);
}
ull fact(ull x) //Factorial
{
    return !x ? 1 : x * fact(x - 1);
}
ull cnk(ull n, ull k) //The number of combinations
{
    return (fact(n)/(fact(k)*fact(n-k)));
}

ull q(const ull n, const ull k) //Procedure "q" for task
{
    if(k > 0 && (n == 1 || n == 0))
    {
            return 1;

    }
    if(k <= 0)
        {
            return 0;
        }

    return (q(n - k, k - 1) + q(n, k - 1));
}
uint prime(uint a) //Prime
    {
        if(a==1)
            return 0;
        uint i = 0;
        for(i = 2;i*i <= a;i++)
            if(a % i == 0)
                return 0;
        return a;
    }
void var1numbA()
{
    printf("\tVariant 1 task A \"Prime numbers\"\n \n");
    uint i = 0, n = 0;
    scanf("%d \n\n", &n);
    assert((10000 > n) && (n > 0));
    uint* massive = (uint*) calloc(n, sizeof(massive));
    for(i = 0;i < n;i++)
        {
        scanf("%d",&massive[i]);
        massive[i] = prime(massive[i]);
        }
    printf("\n\n\n");
    for(i = 0; i < n; i++)
        if(massive[i] > 1)
            printf("%d ", massive[i]);
    printf("\n\n\n");
    free(massive);
}
void var1numbB()
{
    printf("\tVariant 1 task B \"Free From Square\"\n\n");
    ull f = 0, N = 0, i = 2, k = 0;
    scanf("%lld", &N);
    assert((pow(2, 31) > N) && (N > 0));
    f = N;
    for(i;i < (f/2) + 1;)
        {
            if(N % i == 0)
                {
                    if(k > 0)
                    {
                        printf("YES\n\n\n");
                        return;
                    }
                    else
                    {
                        N /= i;
                        k++;
                    }
                }
                else
                {
                    i++;
                    k = 0;
                }
        }
    printf("NO\n\n\n");

}
void var1numbC()
{
    ull n;
    printf("\tVariant 1 task C \"Weigh\"\n\n");
    scanf("%lld", &n);
    while(n != 0)
        {
            if(n % 4 == 0)
                n /= 4;
            if((n - 1) %4 == 0)
                n = (n - 1) / 4;
            if((n + 1) % 4 == 0)
                n = (n + 1) / 4;
            if (((n + 1) % 4 != 0)&& ((n - 1) % 4 != 0)&&(n % 4 != 0))
            {
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
}
void var2numbA()
{
    printf("\tVariant 2 task A \"Transposition\"\n\n");
    ull n = 0, i = 1, j = 1;
    ull** massive;
    printf("%d %d", sizeof(ull**), sizeof(ull));
    scanf("%d", &n);
    assert(n < 50);
    massive = (ull**) calloc (n, sizeof(ull));
    for(i = 0;i < n; i++)
        {
    massive[i] = (ull*) calloc (n, sizeof(ull));
        for(j = 0;j < n; j++)
            {
                scanf("%lld",&massive[i][j]);
                assert(abs(massive[i][j]) < (pow(2, 31)));
            }
        }
     printf("\n");
    for(i = 0;i < n; i++)
        {
        for(j = 0;j < n; j++)
            printf("%lld ",massive[j][i]);
        printf("\n");
        free(massive[i]);
        }
    free(massive);
}
void var2numbB()
{
    printf("\tVariant 2 task B \"Root normalization\"\n\n");
    ull n = 0, i = 2, root = 1, remainder = 1, j = 0;
    scanf("%d", &n);
    assert((pow(2, 31) > n) && (n > 0));
    printf("\n");
    while(n != 1)
        {
            if (n % i == 0)
            {   if(j == 0)
                {
                    n /= i;
                    remainder *= i;
                    j++;
                }
                else
                {
                    n /= i;
                    root *= i;
                    remainder /= i;
                    j--;
                }

            }
            else
                {
                    i++;
                    j = 0;
                }
        }
        printf("%lld %lld", remainder, root);
        printf("\n");
}

void var2numbC()
{
    printf("\tVariant 2 task C \"Prime by number\"\n\n");
    ull n = 0, nPrime = 2, Counter = 0;
    scanf("%d", &n);
    assert((10000 >= n) && (n > 0));
    printf("\n");
    while (Counter != (n + 1))
        {
            if(n == 1)
                {printf("2");return;}

            if(prime(nPrime) != 0)
                {
                    Counter++;
                    if(Counter == n)
                    {
                        printf("%lld \n", nPrime);
                        return ;
                    }

                }
            nPrime++;
        }


    printf("\n");
}
void var2numbD()
{
    printf("\tVariant 2 task D \"Number of expansions\"\n\n");
    ull n = 0;
    scanf("%d", &n);
    assert((500 > n) && (n > 0));
    printf("%lld\n", q(n,n));

}
void var3numbB()
{
    printf("\tVariant 3 task B \"PrimeS by numberS\"\n\n");
    ull n = 0, nPrime = 1, k = 0, j = 0;
    scanf("%d", &n);
    assert((10000 >= n) && (n > 0));
    uint* matrix = (uint*) calloc(n, sizeof(matrix));
    for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[j]);
            assert((10000 >= matrix[j]) && (matrix[j] > 0));
        }
    printf("\n");
    for(j = 0; j < n; j++)
    {
        k = 0; nPrime = 1;
        while (k != (matrix[j] + 1))
        {
            if(prime(nPrime) != 0)
                {
                    k++;
                    if(k == matrix[j])
                    {
                        printf("%lld ", nPrime);
                        break;
                    }

                }
            nPrime++;
        }
        }
    free(matrix);
    printf("\n")

}
void var3numbA()
{
    printf("\tVariant 3 task A \"Least common multiple of three numbers\"\n\n");
    ull a = 0, b = 0, c = 0, result = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    assert((pow(2, 31) > a) && (a > 0));
    assert((pow(2, 31) > b) && (b > 0));
    assert((pow(2, 31) > c) && (c > 0));
    result = nok(nok(a,b),c);
    printf("%lld \n", result);

}
void var4numbB()
{
   printf("\tVariant 4 task B \"Filter characters\"\n\n");
    char str[3000];
    ull i = 0;
    fflush(stdin);
    gets(str);
    for(i = 0; i < strlen(str); i++)
        if(iswspace(str[i+1]) && iswspace(str[i]))
            {

            }
        else
            if((58 > str[i]) && (str[i] > 47))
                {
                    str[i] = '#';
                    printf("%c", str[i]);
                }
            else
                if(iswpunct(str[i]))
                {

                }
                else
                {
                    str[i] = tolower(str[i]);
                    printf("%c", str[i]);
                }


    printf("\n");
}
void var4numbC()
{
    printf("\tVariant 4 task C \"Turning words\"\n\n");
    char str[100];
    int i = 0, len = 0;
    fflush(stdin);
    gets(str);
    len = strlen(str);
    for(i = len-1; i >= 0; i--)
      printf("%c", str[i]);
}
int main()
{
    var1numbA();
    var1numbB();
    var1numbC();
    var2numbA();
    var2numbB();
    var2numbC();
    var2numbD();
    var3numbA();
    var3numbB();
    var4numbB();
    var4numbC();
    return 0;
}
