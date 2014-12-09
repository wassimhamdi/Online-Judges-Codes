#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genre {masculin,feminin};
enum etat_civile {marie,celibataire,veuf,divorce};

typedef struct
{
    char nom[20];
    char prenom[25];
    unsigned int age;
    enum genre g;
    enum etat_civile etat;
} Personne;

typedef struct
{
    struct Element *suiv;
    struct Element *prev;
    Personne pers;

} Element;

int choix;
Element *start, *end;

void choisir();
void traitement();
int comparaisonnom(char atrouver[10],char x[10]);
Personne saisiepersonne();

int main()
{

    choix=-1;
    start=NULL;
    end=NULL;

    do
    {
        choisir();
        if (choix==5)
        {
            return(0);
        };
        traitement();
    }
    while (choix!=5);



    return 0;
}

void choisir()
{
    int a;

    printf("\nMenu:\n\t0)voir tous les entrees\n\t1)nouvelle entree\n\t2)recherche\n\t3)modification\n\t4)suppression\n\t5)quitter le programme\n");

    a=-1;

    do
    {
        scanf("%d",&a);
    }
    while ((a>5)+(a<0));
    choix=a;
}

void traitement()
{
    int i;
    Personne p;
    Element *point;

    switch (choix)
    {
    case 0:
        point=start;
        i=0;

        if (point==NULL)
        {
            printf("aucune entree\n");
        }

        else
        {

            do
            {
                p=point->pers;
                printf("%d) %s %s\n",i,p.nom,p.prenom);
                i=i+1;
                point=point->suiv;
            }
            while(point!=NULL);
        }

        break;

    case 1:
        ajoutelement();
        break;

    case 2:
        recherche();
        break;
    }


}

void ajoutelement()
{
    Element *point, *nouv;

    if (start==NULL)
    {
        start=malloc(sizeof(Element*));
        start->suiv=NULL;
        start->prev=NULL;
        start->pers=saisiepersonne();
        end=start;
    }

    else
    {
        nouv=malloc(sizeof(Element));
        nouv->prev=end;
        nouv->suiv=NULL;
        nouv->pers=saisiepersonne();
        end->suiv=nouv;
        end=nouv;
    }
}


Personne saisiepersonne()
{
    Personne X;
    int entree;

    printf("nom\n");
    scanf("%s",X.nom);
    printf("prenom\n");
    scanf("%s",X.prenom);
    printf("age\n");
    scanf("%u",&X.age);
    do
    {
        printf("sexe (0=m,1=f)");
        scanf(" %d",&entree);
    }
    while ((entree!=0)&(entree!=1));

    switch (entree)
    {
    case 0:
        X.g= masculin;
        break;
    case 2:
        X.g= feminin;
        break;
    }
    do
    {
        printf("etat civil (1=marie; 2=celibataire; 3=veuf; 4=divorce)\n");
        scanf(" %d",&entree);
    }
    while ((entree!=1)&&(entree!=2)&&(entree!=3)&&(entree!=4));
    switch (entree)
    {
    case 1:
        X.etat= marie;
        break;
    case 2:
        X.etat= celibataire;
        break;
    case 3:
        X.etat= veuf;
        break;
    case 4:
        X.etat= divorce;
        break;
    }

    return(X);
}

void recherche()
{
    int i,rechpar;
    unsigned int atrouv;
    char atrouver[10];
    Personne p;
    Element *point;

    rechpar=0;

    do
    {
        printf("rechercher par(1=nom;2=age;3=etat civile\n");
        scanf("%d",&rechpar);
    }
    while ((rechpar<0)*(rechpar>4));


    switch(rechpar)
    {
    case 1:
        printf("A rechercher");
        scanf("%s",&atrouver);
        printf("\n",atrouver);
        point=start;
        i=0;

        if (point==NULL)
        {
            printf("aucune entree\n");
        }
        else
        {
            printf("resultats de la recherche\n");
            do
            {
                p=point->pers;
                if (comparaisonnom(atrouver,p.nom))
                {
                    printf("%d) %s %s\n",i,p.nom,p.prenom);
                }
                i=i+1;
                point=point->suiv;
            }
            while(point!=NULL);
        }
        break;

    case 2:
        printf("age recherche\n");
        scanf("%u",&atrouv);
        point=start;
        i=0;

        if (point==NULL)
        {
            printf("aucune entree\n");
        }

        else
        {
            printf("resultats de la recherche\n");
            do
            {
                p=point->pers;
                if (atrouv==p.age)
                {
                    printf("%d) %s %s\n",i,p.nom,p.prenom);
                }
                i=i+1;
                point=point->suiv;
            }
            while(point!=NULL);
        }
        break;
    }
}

int comparaisonnom(char atrouver[10],char x[10])
{

    char * pch;
    pch = strstr (x,atrouver);
    return(pch);
}
