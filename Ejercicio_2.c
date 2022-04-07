#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *nombres[5];
    char *Buff;
    int i;

    Buff =  (char *)malloc(100*sizeof(char));
    printf("\nIngrese 5 nombres:\n");
    for(i=0;i<5;i++)
    {
        printf("Nombre %d: ",(i+1));
        gets(Buff);
        nombres[i]= (char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
        //free(Buff);
    }
    
    for(i=0;i<5;i++)
    {
        printf("%s\n", nombres[i]);
    }
    free(Buff);

    return 0;
}