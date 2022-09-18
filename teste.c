#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>

 struct medicament {
    int code;
    char nom[100];
    int quantite;
    float prix;
} ;

void AjouterProduit();
void AjouterPlusieurProduit();
void ListerProduit();
void AcheterProduit();
void RechercheProduit();
void EtatDeStock();
void AlimenterStock();
void SupprimeProduit();
void StatistiqueVente();
 
int main()
{    
     printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\t\t\t\t\t     GESTION PHARMACIE \n\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
     //printf("----------\t----------\t----------\t----------\t--------\t--------\t---------\n");
     printf("\t\t\t\t\t\t [MENU] \t\t\t\t\t\t\t\t\t\t\n\n\n");
        int nbr;
    printf("\t\t\t\t\t1-Ajouter un nouveau produit.\n\n");
    printf("\t\t\t\t\t2-Ajouter plusieurs nouveaux produits.\n\n");
    printf("\t\t\t\t\t3-Lister tous les produits.\n\n");
    printf("\t\t\t\t\t4-Acheter produits.\n\n");
    printf("\t\t\t\t\t5-Recherche les produits.\n\n");
    printf("\t\t\t\t\t6-Etat du stock.\n\n");
    printf("\t\t\t\t\t7-Alimenter le stock.\n\n");
    printf("\t\t\t\t\t8-Supprimer les produits par code.\n\n");
    printf("\t\t\t\t\t9-Stasitique de vente.\n\n");
    printf("\t\t\t\t\t10-Exit.\n\n");
    printf("\t\t\t\t\tchoisi une service: ");
    scanf(" %d",&nbr);
    system("cls");
    switch (nbr)
    {
    case 1:
            AjouterProduit();

        break;
    case 2:
            AjouterPlusieurProduit();
            break;
    case 3:
           ListerProduit();
            break;
    case 4:
            AcheterProduit();
            break;
    case 5:
            RechercheProduit();
            break;
    case 6:
            EtatDeStock();
            break;
    case 7:
            AlimenterStock();
            break;
    case 8:
            SupprimeProduit();
            break;
    case 9:
            StatistiqueVente();
            break;
    case 10: 
            exit(0);
            break;
    default:
    printf("entrer correct choix.");
        break;
    }
 

    return 0;
}
void AjouterProduit()
{
    //ajouter products
   struct medicament M1;
  printf("entrer product: \n");
  printf("enter code produit: ");
  scanf(" %d",&M1.code);
  printf("entrer name of product: ");
  scanf(" %s",M1.nom);
  //printf("\n");
  printf("entrer Quantite: ");
  scanf(" %d",&M1.quantite);
  printf("entrer prix de produit (DH): ");
  scanf(" %.2f",&M1.prix);

  printf("show information: ");
  printf("%d %s %d %f ",M1.code,M1.nom,M1.quantite,M1.prix);
}
void AjouterPlusieurProduit()
{  
    int nbr_produit;
    printf("veuillez saisir nombre de produits: ");

}
void ListerProduit()
{
    int nbr_lister;
     printf("1-Lister les produits selon ordre alphabetique.\n");
            printf("2-Lister les produits selon ordre decroissant du prix.\n");
            printf("choisi methode de lister: ");
            scanf(" %d",&nbr_lister);
            system("cls");
            switch (nbr_lister)
            {
            case 1:
                   printf("entrer les alphabetique des produits.");
                break;
            case 2:
                   printf("entrer les prix des produits.");
                      
            
            default:
                break;
            }

}
void AcheterProduit()
{

}
void RechercheProduit()
{

}
void EtatDeStock()
{

}
void AlimenterStock()
{

}
void SupprimeProduit()
{

}
void StatistiqueVente()
{

}