/*
ID: kiruayo1
PROG: milk2
LANG: C
*/


#include<stdio.h>
#include<stdlib.h>


void main(){
    FILE *fichier1,*fichier2;
    int n;
    long min=1000000;
    long max=0;
    long i,j,k1,k2,t1,t2;
    unsigned int tab[1000001];

    for(i=0;i<1000001;i++){
        tab[i]=0;
    }
    fichier1=fopen("milk2.in","r");
    fichier2=fopen("milk2.out","w");

    fscanf(fichier1,"%d",&n);

    int tab1[n],tab2[n];


    for(i=0;i<n;i++){
        fscanf(fichier1,"%d %d",&tab1[i],&tab2[i]);
        if(tab1[i]<min){
            min=tab1[i];
        }
        if(tab2[i]>max){
            max=tab2[i];
        }
        for(j=tab1[i];j<tab2[i];j++){
            tab[j]++;
        }
    }
    t1=0;
    t2=0;
    k1=0;
    k2=0;
    for(i=min;i<max;i++){
        if(tab[i]>0){
            k1++;
            k2=0;
            if(k1>t1){
                t1=k1;
            }
        }
        else{
            k2++;
            k1=0;
            if(k2>t2){
                t2=k2;
            }
        }
    }
    fprintf(fichier2,"%ld %ld\n",t1,t2);

    fclose(fichier1);
    fclose(fichier2);
    return 0;
}
