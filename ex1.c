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

void dec2bin(char *numantes, char *numdepois)
{
    char tempchar[BUFFER];
    if(*numantes == '\0')
    {
        *numdepois = '\0';
        return;
    }
    *numdepois = div2(numantes, tempchar) + '0';
    zeroleft(tempchar);
    ++numdepois;
    dec2bin(tempchar,numdepois);
    return;
}

void zeroleft(char *numero)
{
    if(*numero == '0')
        while(*numero != '\0')
        {
            *numero = *(numero + 1);
            ++numero;
        }
    return;
}

void ulprint(ullong x)
{
    char l[BUFFER], h[BUFFER], ndec[BUFFER] = "0";
    dec2bin2(x.l,l);
    dec2bin2(x.h,h);
    bin2dec2(h,l,ndec);
    printf("%s",ndec);
    return;
}
void ssoma(char *ca, char *cb,char *c)
{
    unsigned i=0, val_prox=0, val_atual;
    char xa[BUFFER], xb[BUFFER];
    char *a = xa, *b = xb;
    conca("0",ca,xa);
    conca("0",cb,xb);
    zeros(xa,xb);
    while(*a != '\0')
    {
        ++a;
        ++b;
        ++c;
        ++i;
    }
    *c = '\0';
    --a;
    --b;
    --c;
    while(i != 0)
    {
        val_atual=val_prox;
        val_prox= 0;
        if((*a-'0')+(*b-'0')>=10)
        {

            val_prox=1;
            *c=((*a- '0')+(*b-'0') - 10 + val_atual) + '0';
        }
        else
        {
            *c=(*a-'0')+(*b-'0')+ val_atual+'0';
        }
        --a;
        --b;
        --c;
        --i;
    }
    return;
}

void bin2dec2(char *high, char *low, char *num_dec)
{
    int i = 0, j = 0;
    while (*low != '\0')
    {
        j++;
        ++low;
    }
    --low;
    while(j>0)
    {
        char valor[BUFFER] = "1";
        j--;
        if (*low == '1')
        {
            p2s(valor,i);
            ssoma(num_dec,valor,num_dec);
            zeroleft(num_dec);
        }
        --low;
        ++i;
    }
    j = 0;
    i = BUFFER/2;
    while (*high != '\0')
    {
        j++;
        ++high;
    }
    --high;
    while(j>0)
    {
        char valor[BUFFER] = "1";
        j--;
        if (*high == '1')
        {
            p2s(valor,i);
            ssoma(num_dec,valor,num_dec);
            zeroleft(num_dec);
        }
        --high;
        ++i;
    }
    return;
}
void p2s(char *num, int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        ssoma(num,num,num);
        zeroleft(num);
    }
    return;
}
void uadd(ullong *a, ullong *b, ullong *c)
{
    ullong ltemp;
    ltemp.l = a->l + b->l;
    ltemp.h = a->h + b->h;
    if((ltemp.l < a->l) || (ltemp.l < b->l))
        (ltemp.h)++;
    c->l = ltemp.l;
    c->h = ltemp.h;
    return;
}
