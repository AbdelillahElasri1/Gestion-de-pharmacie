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
    float TTC_produit;
} product;

//Declaration des variables
    int i;
    int nbr_produit;
    product T[100];
    int total_produit=0;
    product temp;
    int NombreDeRecherche;
    int NombreMethodeRecherche;
    int QuantiteMethodeRecherche;
    int CodeProduit;
    int CodeAlimenterStock;
//Declaration des fonctions
void Lister_product();
int RechercheProduit();
void SupprimeProduit();
void AlimenterLeStock();
void EtatDeStock();
void AcheterProduit();




int main()
{
    int repete=0;
    int nbr;
        do {
        do{
            printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\t\t\t\t\t     GESTION PHARMACIE \n\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
            printf("\t\t\t\t\t\t [MENU] \t\t\t\t\t\t\t\t\t\t\n\n\n");
        
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
            
            printf("entrer product:%d \n",total_produit+1);
            printf("enter code produit: ");
            scanf("%d",&T[total_produit].code);
            printf("entrer name of product: ");
            scanf("%s",T[total_produit].nom);
            printf("entrer Quantite: ");
            scanf("%d",&T[total_produit].quantite);
            printf("entrer prix de produit (DH): ");
            scanf("%f",&T[total_produit].prix);
            total_produit++;
        break;
    case 2:
            printf("veuillez saisir nombre de produits: ");
            scanf("%d",&nbr_produit);
            for( i=total_produit;i<nbr_produit+total_produit;i++)
                {
                printf("entrer product %d:\n",i+1);
                printf("enter code produit:");
                scanf("%d",&T[i].code);
                printf("entrer name of product:");
                scanf("%s",T[i].nom);
                printf("entrer Quantite:");
                scanf("%d",&T[i].quantite);
                printf("entrer prix de produit (DH):");
                scanf("%f",&T[i].prix);
                printf("produit est bien ajouter.\n");
                }
                total_produit+=nbr_produit;
            break;
    case 3:
        Lister_product();
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
           AlimenterLeStock();
            break;
    case 8:
            //printf("case 8\n");
            SupprimeProduit(CodeProduit);
            break;
    case 9:
            printf("case 9\n");
            break;
    case 10:
            exit(0);
            break;
    default:
    printf("\t\t\t\t\tentrer correct choix.\n");
        break;
    }

    printf("\t\t\t\t\tvous voullez quite:\n ");
    printf("\t\t\t\t\t 1-non\n \t\t\t\t\t 2-oui\n");
    printf("\t\t\t\t\t=>");
    scanf("%d",&repete);
    system("cls");
    }while(nbr<1 || nbr>10);
        }while(repete==1);

}

void Lister_product()
{
            int affichage;
            printf("Afficher les produit: \n");
            printf("1-Selon l'ordre alphabetique (a to z).\n");
            printf("2-Selon l'ordre decroissant du prix.\n");
            printf("Quoi tu peut:");
            scanf("%d",&affichage);
            switch(affichage)
            {
            case 1:
                   printf("Alphabetique: \n");
                
                   for(int i=0;i<total_produit-1;i++){
                   for(int j=i+1;j<total_produit;j++){
                      if(strcmp(T[i].nom,T[j].nom)==1){
                           temp=T[i];
                           T[i]=T[j];
                           T[j]=temp;
                        }
                        }
                    }
                    
                    printf("Les produits trie par nom croissant : \n\n");
                    for(int i=0;i<total_produit;i++){
                      float  TTC_produit=T[i].prix*0.15;
                        printf("\nNom :%s   Prix :%.2f  prix TTC:%.2f\n",T[i].nom,T[i].prix,T[i].prix+TTC_produit);
                        }

                         break;
             case 2:
                   printf("decroissant du prix: \n");
                    for(int i=0;i<total_produit-1;i++){
                   for(int j=i+1;j<total_produit;j++){
                      if(T[i].prix<T[j].prix){
                           temp=T[i];
                           T[i]=T[j];
                           T[j]=temp;
                        }
                        }
                    }
                    
                    printf("Les produits trie par nom croissant : \n\n");
                    for(int i=0;i<total_produit;i++){
                       float TTC_produit=T[i].prix*0.15;
                        printf("\nNom :%s   Prix :%.2f  prix TTC:%.2f\n",T[i].nom,T[i].prix,T[i].prix+TTC_produit);
                        }
                   
                    break;
            default:
                    printf("entrer choix correct.");
                    break;
            }

}
int RechercheProduit()
{
    printf("Recherche de produit:\n");
  printf("1-code.\n");
  printf("2-Quantite.\n");
  printf("Quoi tu peux:");
  scanf("%d",&NombreDeRecherche);
  switch (NombreDeRecherche)
  {
  case 1:
        printf("saisir code de produit:");
        scanf("%d",&NombreMethodeRecherche);
        for( i=0;i<total_produit;i++)
        {
            if(NombreMethodeRecherche==T[i].code)
                printf("nom: %s\n code: %d\n prix: %.2f\n TTC prix: %.2f\n quantite: %d\n",T[i].nom,T[i].code,T[i].prix,T[i].TTC_produit,T[i].quantite);
        }
    break;
  case 2:
        printf("saisir quantite de produit:");
        scanf("%d",&QuantiteMethodeRecherche);
        for(i=0;i<total_produit;i++)
        {
            if(QuantiteMethodeRecherche==T[i].quantite)
               printf("nom: %s\n code: %d\n prix: %.2f\n TTC prix: %.2f\n quantite: %d\n",T[i].nom,T[i].code,T[i].prix,T[i].TTC_produit,T[i].quantite);
        }
   
    break;
  
  default:
  printf("ERROR");
    break;
  }
}
void SupprimeProduit(int CodeProduit)
{
    int index;
    printf("saisir le code produit:");
    scanf("%d",&CodeProduit);
    for(i=0;i<total_produit;i++)
    {
        if(CodeProduit==T[i].code)
        {
            index=i;
        }
      
    }
        for(i=index;i<total_produit;i++)
        {
           T[i]=T[i+1];
        }
        total_produit--;
    printf("produit supprime success.");
}
void AlimenterLeStock()
{
    int PlusQuantite;
  printf("saisir le code de produit:");
  scanf("%d",&CodeAlimenterStock);
  printf("saisir nombre de Quantite:");
  scanf("%d",&PlusQuantite);
    for(i=0;i<total_produit;i++)
    {
        if(CodeAlimenterStock==T[i].code)
        {
            T[i].quantite+=PlusQuantite;
            printf("quantite de produit: %d",T[i].quantite);
            break;
        }
    }
}
void EtatDeStock()
{
    for(i=0;i<total_produit;i++)
    {
        if(T[i].quantite<3)
        {
            printf(" nom: %s\n code: %d\n quantite: %d\n prix: %.2f\n",T[i].nom,T[i].code,T[i].quantite,T[i].prix);
        }
    }
}
void AcheterProduit()
{
    int CodeAcheter,QuantiteAcheter;
    printf("saisir le code de produit:");
    scanf("%d",&CodeAcheter);
    printf("entrer la quantite tu peut acheter:");
    scanf("%d",&QuantiteAcheter);
    for(i=0;i<total_produit;i++)
    {
        if(CodeAcheter==T[i].code)
        {
            if(QuantiteAcheter>T[i].quantite)
            {
                printf("!!STOP!!==>la quantite actuellement de produit : %d\n",T[i].quantite);
                break;
            } else { 
            T[i].quantite-=QuantiteAcheter;
            printf("voila l'achat est terminer success.\n");
            printf("la quantite reste apres achat : %d\n",T[i].quantite);
            break;
            }
        }
    }

}
