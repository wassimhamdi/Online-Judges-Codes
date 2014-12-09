/*
ID: hamdi.w1
PROG: crypt1
LANG: C
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*On peut simplifier*/
/*if product>9999 plus simple que if product/10000=0*/

int test1(int s, int* tab, int n){
    int r,t,s2,trouve,*p;
    if(s/1000!=0){
        return 0;
    }
    else{
        s2=s;
        for(t=0;t<3;t++){
            trouve=0;
            r=s2%10;
            s2=s2/10;
            for(p=tab;p<tab+n;p++){
                if(r==*p){
                    trouve=1;
                }
            }
            if (trouve==0){
                break;
            }
        }
        return trouve;
    }
}

int test2(int s, int* tab, int n){
    int r,t,s2,trouve,*p;
    if(s/10000!=0){
        return 0;
    }

    else{
        s2=s;
        for(t=0;t<4;t++){
            trouve=0;
            r=s2%10;
            s2=s2/10;
            for(p=tab;p<tab+n;p++){
                if(r==*p){
                    trouve=1;
                }
            }
            if (trouve==0){
                break;
            }
        }
        return trouve;
    }
}

int main(){
    FILE *fichier1,*fichier2;

    fichier1=fopen("crypt1.in","r");
    fichier2=fopen("crypt1.out","w");

    int i,j,k,t,i2,j2,k2,t2,r1,r2,r3,trouve=1,n,s,sol,c1,c2;

    fscanf(fichier1,"%d",&n);

    int tab[n],tab2[n][n][n];

    for(i=0;i<n;i++){
        fscanf(fichier1,"%d",&tab[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                tab2[i][j][k]=tab[i]*100+tab[j]+10*tab[k];
            }
        }
    }

    sol=0;

    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                for(c1=0;c1<n;c1++){
                    s1=tab[c1]*tab2[i][j][k];
                    if(s1/1000!=0){
                        continue;
                    }
                    for(t=0;t<3;t++){
                        trouve=0;
                        r1=s1%10;
                        s1=s1/10;
                        for(t2=0;t2<n;t2++){
                            if(r1==tab[t2]){
                                trouve=1;
                            }
                        }
                        if (trouve==0){
                            break;
                        }
                    }
                    if(trouve==0){
                        break;
                    }
                    for(c2=0;c2<n;c2++){
                        s2=tab[c2]*tab2[i][j][k];
                        if(s1/1000!=0){
                            continue;
                        }
                        for(t=0;t<3;t++){
                            trouve=0;
                            r2=s2%10;
                            s2=s2/10;
                            for(t2=0;t2<n;t2++){
                                if(r2==tab[t2]){
                                    trouve=1;
                                }
                            }
                            if (trouve==0){
                                break;
                            }
                        }
                        if(trouve==0){
                            break;
                        }
                        s3=s1+10*s2;
                        if(s1/10000!=0){
                            continue;
                        }
                        for(t=0;t<4;t++){
                            trouve=0;
                            r3=s3%10;
                            s3=s3/10;
                            for(t2=0;t2<n;t2++){
                                if(r3==tab[t2]){
                                    trouve=1;
                                }
                            }
                            if (trouve==0){
                                break;
                            }
                        }
                        if(trouve==0){
                            break;
                        }
                        else{
                            sol++;
                        }
                    }
                }
            }
        }
    }
    */
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                for(c1=0;c1<n;c1++){
                    for(c2=0;c2<n;c2++){
                        s=(tab[c1]+10*tab[c2])*tab2[i][j][k];
                        if(test1(tab[c1]*tab2[i][j][k],tab,n) && test1(tab[c2]*tab2[i][j][k],tab,n) && test2(s,tab,n)){
                            sol++;
                        }
                    }
                }
            }
        }
    }


    fprintf(fichier2,"%d\n",sol);

    fclose(fichier1);
    fclose(fichier2);
    return 0;
}
