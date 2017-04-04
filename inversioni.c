#include <stdio.h>
#include <stdlib.h>
#include "inversioni.h"

int merge(int A[], int p, int q, int r/*, int *inv*/){
    int dim1=q-p+1;
    int dim2=r-q;
    int i, j, k, s;
    int *L, *R;
    int sum=0;
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
        if(i<dim1 && j<dim2){
            if(L[i]<=R[j]){
                A[k]=L[i];
                i++;
            }
            else{
                A[k]=R[j];
                j++;
                sum+=(dim1-i);
                printf("inv = %d, val = %d, dim1 = %d, i = %d\n",100/**inv*/, sum, dim1, i);
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
    /**inv=*inv+sum;
    return *inv;*/
    return sum;
}

int inversioni(int v[], int inf, int sup){
    int q;
    int val=0;
    /*int inv=0;*/
    if(inf<sup){
        q=(inf+sup)/2;
        inversioni(v, inf, q);
        inversioni(v, q+1, sup);
        val+=merge(v, inf, q, sup/*, &inv*/)/*+inv*/;
        /*val=inv;*/
    }
    return val;
}
