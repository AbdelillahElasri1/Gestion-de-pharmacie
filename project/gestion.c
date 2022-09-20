#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>

 typedef struct  {
    int code;
    char nom[100];
    int quantite;
    float prix;
} product;
typedef struct  {
    int code;
    float prixTTC;
    int jour;
    int mois;
    int année;
} achat;



void AjouterProduit();
void AjouterPlusieurProduit();
void ListerProduit();
void AcheterProduit();
int RechercheProduit();
void EtatDeStock();
void AlimenterStock();
void SupprimeProduit();
void StatistiqueVente();
void listProduitdeTest();
 
    product Abdo[100];
int main()
{     

  
    
    

   
     printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\t\t\t\t\t     GESTION PHARMACIE \n\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
     printf("\t\t\t\t\t\t [MENU] \t\t\t\t\t\t\t\t\t\t\n\n\n");
        int nbr;
        int repeate=0;

    do {
        do{


        
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
    scanf("%d",&nbr);
        }while(nbr<1 || nbr>10);
    system("cls");
    switch (nbr)
    {
    case 1:
            AjouterProduit();

        break;
    case 2:
            AjouterPlusieurProduit(Abdo);
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
           // EtatDeStock();
           printf("hhhh");
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
 
   printf("retour au menu principale\n");
   printf("1-oui\n 2-non");
   scanf("%d",&repeate);

    
        
    } while(repeate==1);
    return 0;
}
void AjouterProduit()
{
    //ajouter products
    product M1;
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

//   printf("show information: ");
//   printf("%d %s %d %f ",M1.code,M1.nom,M1.quantite,M1.prix);
}
void AjouterPlusieurProduit(product T[])
{  
    int nbr_produit;
    printf("veuillez saisir nombre de produits: ");
    scanf("%d",&nbr_produit);
    for(int i=0;i<nbr_produit;i++)
    {
    
    printf("entrer product %d:\n",i);
    printf("enter code produit:");

    scanf("%d",&T[i].code);
    
    printf("entrer name of product:");
    scanf("%s",T[i].nom);
  //printf("\n");
    printf("entrer Quantite:");
    scanf("%d",&T[i].quantite);
    printf("entrer prix de produit (DH):");
    scanf("%.2f",&T[i].prix);
    printf("produit est bien ajouter.");
    }

}
void ListerProduit()
{
    int nbr_lister,i,j;
    //int T[14]={2,8,3,54,32,34,45,6,564,335,34,56,34,13};
   // int T[10]={3,7,1,9,6,5,10,26,48,30};
   int T[];
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
                   //printf("entrer les prix des produits.");
                    

    
    for (int i=0;i<14;i++)
    {
    product swap;
        if(T[i].prix>T[i+1].prix)
        {
             swap=T[i];
            T[i]=T[i+1];
            T[i+1]=swap;
        } 
       printf("%d %s %d %f ",T[i].code,T[i].nom,T[i].quantite,T[i].prix);

    // }
    // min=T[0];
    // max=T[14];
    // printf("max=%d\n",max);
    // printf("min=%d",min);
    break;
    default:
    printf("error");
    break;
            }

            

}
void AcheterProduit()
{

}
int RechercheProduit(int codeproduit)
{
    for (int i = 0; i < 20; i++)
    {
        if (Abdo[i].code==codeproduit)
        {
            printf("%d %s %d %f",Abdo[i].code,Abdo[i].nom,Abdo[i].quantite,Abdo[i].prix);
        }
    }
    

}
void EtatDeStock()
{

}
void AlimenterStock()
{

}
void SupprimeProduit(int codePrSupprimer)
{ 
    int posCodePrSupprimer = RechercheProduit(codePrSupprimer);
    for (int i = posCodePrSupprimer; i < 100; i++)
    {
        Abdo[i] = Abdo[i+1];
    }
    printf("======================================\n");
    ListerProduit();

}
void StatistiqueVente()
{

}
}
