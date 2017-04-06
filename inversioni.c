#include <stdio.h>
#include <stdlib.h>
#include "inversioni.h"


int merge(int A[], int p, int q, int r){
    int dim1=q-p+1;
    int dim2=r-q;
    int i, j, k, s;
    int *L, *R;
    int sum=0;
    L=(int*)malloc(sizeof(int)*dim1);
    R=(int*)malloc(sizeof(int)*dim2);
    for(i=0; i<dim1; i++){
        L[i]=A[p+i];
    }
    for(i=0; i<dim2; i++){
        R[i]=A[q+i+1];
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
    return sum;
}


int inversioni(int v[], int inf, int sup){
    int invsx, invdx, invtot, invparz;
    int q;
    invdx=invsx=invtot=invparz=0;
    if(inf<sup){
        q=(inf+sup)/2;
        invsx=inversioni(v, inf, q);
        invdx=inversioni(v, q+1, sup);
        invtot=invdx+invsx+merge(v, inf, q, sup);
    }
    return invtot;
}
