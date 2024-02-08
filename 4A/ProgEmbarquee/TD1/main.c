#include <stdio.h>


struct Vin
{
    char nom[50];
    char type[20];
    int annee;
    int nbBouteilles;
};

struct Cave
{
    struct Vin vins[50];
    int compteur;
};

void saisie_vin(struct Vin *vin)
{
    printf("Nom de la bouteille : ");
    scanf("%s", vin->nom);
    printf("Type de la bouteille : ");
    scanf("%s", vin->type);
    printf("Année de la bouteille : ");
    scanf("%d", &vin->annee);
    printf("Nombre de la bouteille : ");
    scanf("%d", &vin->nbBouteilles);
    printf("\n");
}

void saisie_vin_cave(struct Cave *cave)
{
    if (cave->compteur < 50) {
        saisie_vin(&(cave->vins[cave->compteur]));  
        cave->compteur++;
    } else {
        printf("La cave est pleine, impossible d'ajouter plus de vins.\n");
    }
}

void afficher_cave(struct Cave *cave)
{
    printf("Il y a %d vin(s) différent(s) dans la cave actuellement.\n", cave->compteur);
    for(int k=0; k<cave->compteur; k++)
    {
        printf("Dans la case numéro %d, il y a le vin suivant :\n", k);
        printf("     Nom : %s\n",cave->vins[k].nom);
        printf("     Type : %s\n",cave->vins[k].type);
        printf("     Année : %d\n",cave->vins[k].annee);
        printf("     Quantités : %d\n",cave->vins[k].nbBouteilles);
    }
    printf("\n");
}

void afficher_cave_anne(struct Cave *cave, int annee)
{
    printf("Les vins disponibles dans la cave de l'année %d sont les suivant :\n",annee);
    for(int k=0; k<cave->compteur; k++)
    {
        if(cave->vins[k].annee == annee)
        {
            printf("Dans la case numéro %d, il y a le vin suivant :\n", k);
            printf("     Nom : %s\n",cave->vins[k].nom);
            printf("     Type : %s\n",cave->vins[k].type);
            printf("     Année : %d\n",cave->vins[k].annee);
            printf("     Quantités : %d\n",cave->vins[k].nbBouteilles);
        }
    }
    printf("\n");
}

void supprimer_vin(struct Cave *cave, int num)
{
    if (num >= 0 && num < cave->compteur) {
        
        for (int i = num; i < cave->compteur - 1; i++) {
            cave->vins[i] = cave->vins[i + 1];
        }
        cave->compteur--;
    } 
}

void boire(struct Cave *cave)
{
    int quantite = 0;
    int nbCase = 0;

    afficher_cave(cave);

    printf("Saisir le numéro de la case du vin à boire : ");
    scanf("%d", &nbCase);
    printf("Saisir le nombre de bouteilles à boire : ");
    scanf("%d", &quantite);

    if(quantite > 0 || nbCase < 0 || nbCase > cave->compteur)
    {
        if(quantite > cave->vins[nbCase].nbBouteilles)
        {
            printf("Toutes les bouteilles ont été bues !\n");
            supprimer_vin(cave,nbCase);
        }
        else 
        {
            printf("La quantité de bouteille restante à été mis à jour.\n");
            cave->vins[nbCase].nbBouteilles = cave->vins[nbCase].nbBouteilles - quantite;
        }
    }
    else{
        printf("Erreur dans la saisie de la case ou des quantités !\n");
    }
    printf("\n");
}

int main(){
    struct Cave cave = { .compteur = 0 };
    saisie_vin_cave(&cave);
    saisie_vin_cave(&cave);
    //afficher_cave_anne(&cave,2018);
    //supprimer_vin(&cave,0);
    //afficher_cave(&cave);
    boire(&cave);
    afficher_cave(&cave);
    return 0;
}