#include <stdio.h>
#include <stdlib.h>
#include "inversioni.h"

int main()
{
    int i, ris, dim;
    dim=5;
    int v[]={5,3,8,4,3};
    for(i=0; i<dim; i++)
        printf("%d ",v[i]);
    printf("\n");
    ris=inversioni(v,0,dim-1);
    printf("inversioni = %d\n", ris);
    for(i=0; i<dim; i++)
        printf("%d ",v[i]);
    return 0;
}
