#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>

 typedef struct  {
   long long int code;
    char nom[100];
    int quantite;
    float prix;
} medicament;



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
 
    medicament Abdo[100];
int main()
{     
    medicament A={213324,"abdc",3234,42};
    medicament B={696694,"gfdshb",123,32};
    medicament C={7432,"kajabd",764,54};
    medicament D={326474,"owr",92346,97};
    medicament E={82345,"uwegf",4376,85};
    medicament F={7432,"wejgr",8756,99};
  
    
    

     Abdo[0]=A;
     Abdo[1]=B;
     Abdo[2]=C;
     Abdo[3]=D;
     Abdo[4]=E;
     Abdo[5]=F;

     printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\t\t\t\t\t     GESTION PHARMACIE \n\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
     //printf("----------\t----------\t----------\t----------\t--------\t--------\t---------\n");
     printf("\t\t\t\t\t\t [MENU] \t\t\t\t\t\t\t\t\t\t\n\n\n");
        //float nbr;
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
    medicament M1;
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
void AjouterPlusieurProduit(medicament T[])
{  
    int nbr_produit;
    printf("veuillez saisir nombre de produits: ");
    scanf("%d",&nbr_produit);
    for(int i=0;i<nbr_produit;i++)
    {
          
  printf("entrer product %d:\n",i);
  printf("enter code produit:");
  //printf("%d",nbr_produit);

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
    int T[10]={3,7,1,9,6,5,10,26,48,30};
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
                   
    int i ;
    int swap;

    int T[14]={2,8,3,54,32,34,45,6,564,335,34,56,34,13};
    for (i=0;i<14;i++)
    {
        if(T[i]>T[i+1])
        {
             swap=T[i];
            T[i]=T[i+1];
            T[i+1]=swap;
        } 
       printf("%d ",T[i]);

    }
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
void listProduitdeTest(){
    medicament c1 = {6118000060154 ,"GLUCOR",200,230,20};
    medicament c2 = {6118000241324 ,"REVOCIR",100,115,10};
    medicament c3 = {6118000070573 ,"LISASPIN",140,230,20};
    medicament c4 = {6118000061106 ,"ASPEGIC ENF",300,340,4};
    medicament c5 = {6118000060857 ,"SURGAM",20,25,10};
    medicament c6 = {6118000061243 ,"EXACYL",10,12,50};
    medicament c7 = {6118001141357 ,"ZENTEL",20,30,11};
    medicament c8 = {6118000022251 ,"ZYLORIC",30,33,1};
    medicament c9 = {6118001081288 ,"XATRAL",222,250,2};
    medicament c10 ={6118001182657 ,"AMIKLIN",230,280,2};
    medicament c11 ={6118000071136 ,"DIPICOR",123,140,100};
    medicament c12 ={6118000180043 ,"AMODEX",222,234,45};
    medicament c13 ={6118000030102 ,"AXIMYCINE",33,44,7};
    medicament c14 ={6118000161059 ,"CLAMOXYL",44,50,23};
    medicament c15 ={6118000161189 ,"PENAMOX",23,44,4};
    medicament c16 ={6118000160038 ,"AMOXIL",44,66,11};
    medicament c17 ={6118000160359 ,"CLAMOXYL",66,88,99};
    medicament c18 ={6118000160724 ,"PENAMOX",210,230,30};
    medicament c19 ={6118000031161 ,"AXIMYCINE",122,255,37};
    medicament c20 ={6118001200818 ,"FUCITHALMIC",140,160,55};
    Abdo[0] = c1;
    Abdo[1] = c2;
    Abdo[2] = c3;
    Abdo[3] = c4;
    Abdo[4] = c5;
    Abdo[5] = c6;
    Abdo[6] = c7;
    Abdo[7] = c8;
    Abdo[8] = c9;
    Abdo[9] = c10;
    Abdo[10] = c11;
    Abdo[11] = c12;
    Abdo[12] = c13;
    Abdo[13] = c14;
    Abdo[14] = c15;
    Abdo[15] = c16;
    Abdo[16] = c17;
    Abdo[17] = c18;
    Abdo[18] = c19;
    Abdo[19] = c20;
};