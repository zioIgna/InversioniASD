#include <stdio.h>
#include <stdlib.h>
#include "inversioni.h"

int merge(int A[], int p, int q, int r, int *inv){
    int dim1=q-p+1;
    int dim2=r-q;
    int i, j, k, s;
    int *L, *R;
    L=(int*)malloc(sizeof(int)*dim1);
    R=(int*)malloc(sizeof(int)*dim2);
    for(i=0; i<dim1; i++){
        L[i]=A[p+i];
        printf("L[%d] = %d\n",i,L[i]);
    }
    for(i=0; i<dim2; i++){
        R[i]=A[q+i+1];
        printf("R[%d] = %d\n",i,R[i]);
    }
    i=0;
    j=0;
    for(k=p; k<=r; k++){
        printf("ora inv = %d\n",*inv);
        if(i<dim1 && j<dim2){
            if(L[i]<=R[j]){
                A[k]=L[i];
                i++;
            }
            else{
                A[k]=R[j];
                j++;
                *inv+=(dim1-i);
                printf("inv = %d, dim1 = %d, i = %d\n",*inv, dim1, i);
                for(s=0; s<k; s++)
                    printf("A[%d] = %d\n",s, A[k]);
            }
        }
        else{
            if(i>=dim1){
                A[k]=R[j];
                j++;
            }
            else{
                if(j>=dim2){
                    A[k]=L[i];
                    i++;
                }
            }
        }
    }
    return *inv;
}

int inversioni(int v[], int inf, int sup){
    int q;
    int inv=0;
    if(inf<sup){
        q=(inf+sup)/2;
        inversioni(v, inf, q);
        inversioni(v, q+1, sup);
        inv+=merge(v, inf, q, sup, &inv);
    }
    return inv;
}
