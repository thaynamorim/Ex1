int main
return 0;

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
