#include <stdio.h>
#include <stdlib.h>

#define MAXULLONG "340282366920938463463374607431768211455"
#define BUFFER 128

typedef struct sl
{
    unsigned long h;
    unsigned long l;
} ullong;

void ulet(ullong *var, char *num);
int div2(char *numantes, char *numdepois);
void zeroleft(char *numero);
void dec2bin(char *numantes, char *numdepois);
unsigned long po2(int i);
void uadd(ullong *a, ullong *b, ullong *c);
void zeros(char *a, char *b);
void conca(char *a, char *b, char *ab);
void ssoma(char *a, char *b,char *c);
void p2s(char *num, int n);
void mult2(char *num);
void dec2bin2(unsigned long dec, char *ebinn);
void ulprint(ullong a);
void bin2dec2(char *high, char *low, char *num_dec);

int main(void)
{
    ullong x, y, z;
    ulet(&x,"170141183460469231731687303715884105726");
    ulet(&y,"170141183460469231731687303715884105723");
    uadd(&x,&y,&z);
    printf("Aritmetica de exemplo: \n");
    ulprint(x);
    printf(" + ");
    ulprint(y);
    printf(" = ");
    ulprint(z);
    printf("\n");
    return EXIT_SUCCESS;
}

void ulet(ullong *var, char *num)
{
    char xbin[BUFFER];
    dec2bin(num, xbin);
    char *xpoint = xbin;
    int i = 0;
    var->l = 0;
    while(i < (BUFFER/2) && *xpoint != '\0')
    {
        var->l += (*xpoint - '0') * po2(i);
        ++xpoint;
        i++;
    }
    var->h = 0;
    i = 0;
    while(i < (BUFFER/2) && *xpoint != '\0')
    {
        var->h += (*xpoint - '0') * po2(i);
        ++xpoint;
        i++;
    }
    return;
}
