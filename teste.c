#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>
#include<time.h>
//Declaration de structure pour les produit
typedef struct  {
    int code;
    char nom[100];
    int quantite;
    float prix;
} product;
// Declaration de structure pour l'achat
typedef struct 
{
    int code;
    int quantite;
    int Day;
    int Month;
    int Years;
    float prix_TTC; 
}Achat;


//Declaration des variables global:
    product T[100];
    product temp;
    Achat Q[100];
    int i;
    int nbr_produit;
    int nbr_produiVendu=0;
    int total_produit=0;
    int NombreDeRecherche;
    int NombreMethodeRecherche;
    int QuantiteMethodeRecherche;
    int CodeProduit;
    int Code,Quantite;
    int AcheterList=0;
    float Total=0;
//Declaration des fonctions utilise dans fonction main:
    void AjouterProduit();
    void AjouterPlusieurProduit();
    void Lister_product();
    void AcheterProduit();
    int RechercheProduit();
    void EtatDeStock();
    void AlimenterLeStock();
    void SupprimeProduit();
    void StatistiqueDeStock();
    int NombreProduitVendus();
    void MaxPrixProduit();
    void MinPrixProduit();



// fonction principale (main):
int main()
{
    int repete=0;   //variable pour repeter Menu.
    int nbr;        //variable pour choisi un choix dans menu.
    do {
    do {
    printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\t\t\t\t\t     GESTION PHARMACIE \n\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
    printf("\t\t\t\t\t\t [MENU] \t\t\t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t************************************************************\n");
    printf("\t\t\t\t\t1-Ajouter un nouveau produit.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t2-Ajouter plusieurs nouveaux produits.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t3-Lister tous les produits.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t4-Acheter produits.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t5-Recherche les produits.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t6-Etat du stock.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t7-Alimenter le stock.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t8-Supprimer les produits par code.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t9-Stasitique de vente.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t\t\t10-Exit.\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t************************************************************\n");
    printf("\t\t\t\t\t=>choisi une service: ");
    scanf(" %d",&nbr);
    //system("cls");

    switch (nbr)
    {
    case 1:
            
            AjouterProduit();
            break;
    case 2:
            AjouterPlusieurProduit();
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
            SupprimeProduit(CodeProduit);
            break;
    case 9:
            StatistiqueDeStock();
            break;
    case 10:
            exit(0);
            break;
    default:
            printf("entrer correct choix.\n");
            break;
    }
    printf("vous voullez quite:\n ");
    printf("1-non\n 2-oui\n");
    printf("=>");
    scanf("%d",&repete);
    system("cls");
    }while(nbr<1 || nbr>10);  // si choix ne trouve pas dans menu il va repeter "entrer correct choix".
    }while(repete==1);
    // fin de main() fonction principale.
}
// les fonctions utilise :
void Lister_product()  // fonction de tri les produits par alphabetique ou par prix.
{
            int affichage;
            printf("Afficher les produit: \n");
            printf("1-Selon l'ordre alphabetique (a to z).\n");
            printf("2-Selon l'ordre decroissant du prix.\n");
            printf("Quoi tu veux:");
            scanf("%d",&affichage);
            switch(affichage)
            {
                case 1:
                printf("Alphabetique: \n");   //tri par selection (alphabetique).
                for(int i=0;i<total_produit-1;i++)
                    {
                    for(int j=i+1;j<total_produit;j++)
                        {
                        if(strcmp(T[i].nom,T[j].nom)==1) //strcmp est une fonction de comparaison entre deux string.
                            {
                                temp=T[i];
                                T[i]=T[j];      // swaping entre les indices
                                T[j]=temp;
                            }
                        }
                    }
                printf("Les produits trie par nom croissant : \n\n");   
                for(int i=0;i<total_produit;i++)
                    {
                        float  TTC_produit=T[i].prix*0.15;   //relation de transaction prix au TTC prix.
                        printf("\nNom:%s\n---------------\nprix:%.2f\n--------------\nprixTTC:%.2f\n",T[i].nom,T[i].prix,T[i].prix+TTC_produit);
                    }

                break;
                case 2:
                    printf("decroissant du prix: \n");   //tri par prix decroissant.
                    for(int i=0;i<total_produit-1;i++)
                        {
                        for(int j=i+1;j<total_produit;j++)
                            {
                            if(T[i].prix<T[j].prix)
                                {
                                    temp=T[i];
                                    T[i]=T[j];
                                    T[j]=temp;
                                }
                            }
                        }
                    printf("Les produits trie par prix decroissant : \n\n");
                    for(int i=0;i<total_produit;i++)   //affichage des produit trie par prix decroissant.
                        {
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
        printf("Quoi tu veux:");
        scanf("%d",&NombreDeRecherche);
    switch (NombreDeRecherche)
            {
            case 1:
                    printf("saisir code de produit:");
                    scanf("%d",&NombreMethodeRecherche);
                    for( i=0;i<total_produit;i++)
                        {
                            if(NombreMethodeRecherche==T[i].code)
                                printf(" nom: %s\n code: %d\n prix: %.2f\n TTC prix: %.2f\n quantite: %d\n",T[i].nom,T[i].code,T[i].prix,Q[i].prix_TTC,T[i].quantite);
                        }
                    break;
            case 2:
                    printf("saisir quantite de produit:");
                    scanf("%d",&QuantiteMethodeRecherche);
                    for(i=0;i<total_produit;i++)
                        {
                            if(QuantiteMethodeRecherche==T[i].quantite)
                                printf(" nom: %s\n code: %d\n prix: %.2f\n TTC prix: %.2f\n quantite: %d\n",T[i].nom,T[i].code,T[i].prix,Q[i].prix_TTC,T[i].quantite);
                        }
                    break;
            default:
                printf("ERROR\n");
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
                total_produit--;   // dans le cas de supprime quelqu'un produit , total_produit - 1.
        printf("produit supprime success.\n");
}
void AlimenterLeStock()
{
    int PlusQuantite;
    int CodeAlimenterStock;
    printf("saisir le code de produit:");
    scanf("%d",&CodeAlimenterStock);
    printf("saisir nombre de Quantite:");
    scanf("%d",&PlusQuantite);
    for(i=0;i<total_produit;i++)
        {
            if(CodeAlimenterStock==T[i].code)  // condition pour recherche de produit.
                {
                    T[i].quantite+=PlusQuantite;
                    printf("quantite de produit: %d \n",T[i].quantite);
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
                } else {
                        printf("tous les produits est superieur a 3.\n");
                        break;
                        }
        }
}
void AcheterProduit()
{
    //float quantiteXprix;
    printf("saisir le code de produit:");
    scanf("%d",&Code);
    printf("entrer la quantite tu peut acheter:");
    scanf("%d",&Quantite);
    for(i=0;i<total_produit;i++)
        {
            if(Code == T[i].code)
                {
                    if(Quantite > T[i].quantite)
                        {
                            printf("!!STOP!!==>la quantite actuellement de produit : %d\n",T[i].quantite);
                            break;
                        } else { 
                                T[i].quantite-=Quantite;
                                //quantiteXprix=T[i].prix * QuantiteAcheter;
                                Q[AcheterList].code=Code;    //stokage de code  produit acheter dans tableau d'Achat => variable AcheterList.
                                Q[AcheterList].quantite=Quantite;  //stokage Quantite de produit acheter dans tableau d'Achat => variable AcheterList.
                                Q[AcheterList].prix_TTC=T[i].prix+T[i].prix*0.15;  //stokage prixTTC de produit acheter dans tableau d'Achat => variable AcheterList.
                                time_t t = time(NULL);
                                struct tm date = *localtime(&t);
                                Q[AcheterList].Day=date.tm_mday;
                                Q[AcheterList].Month=date.tm_mon+1;   // stokage date d'Achat produit 
                                Q[AcheterList].Years=date.tm_year+1900;
                                printf("voila l'achat est terminer success.\n");
                                AcheterList++;
                                break;
                                }
                }
        }
}
void StatistiqueDeStock()
{
    int NombreChoixStatistique;
    // float Total=0;
    float TotalPrixProduit=0;
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    printf("1-Afficher le total des prix des produits vendus en journ??e courante.\n");
    printf("2-Afficher la moyenne des prix des produits vendus en journ??e courante.\n");
    printf("3-Afficher le Max des prix des produits vendus en journ??e courante.\n");
    printf("4-Afficher le Min des prix des produits vendus en journ??e courante.\n");
    printf("Quoi tu veux:");
    scanf("%d",&NombreChoixStatistique);
    switch (NombreChoixStatistique)
    {
    case 1:
            for(i=0;i<AcheterList;i++)
            {
                if(Q[i].Day==date.tm_mday && Q[i].Month==date.tm_mon+1 && Q[i].Years==date.tm_year+1900 )
                    {
                        Total+=Q[i].quantite*Q[i].prix_TTC;
                    }
            }
            printf("Total des prix vendus : %.2f \n",Total);
            break;
    case 2:
            NombreProduitVendus();
            float Moyenne = Total/nbr_produiVendu;
            printf("la moyenne des prix des produit vendus en journee courante:%.2f \n",Moyenne);
            break;
    case 3:
            MaxPrixProduit();
            break;
    case 4:
            MinPrixProduit();
            break;    
    default:
            break;
    }
}
int NombreProduitVendus()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    for(int i=0;i<AcheterList;i++){
        
            if(Q[i].Day==tm.tm_mday && Q[i].Month==tm.tm_mon+1  && Q[i].Years==tm.tm_year+1900){
                nbr_produiVendu++;
            }
        
    }
    return nbr_produiVendu;
}
void MaxPrixProduit(){
    //initialiser la valeur max
    float max=Q[0].prix_TTC;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    for(int j=0;j<AcheterList;j++)
        {
            if(max<Q[j].prix_TTC && Q[j].Day==tm.tm_mday && Q[j].Month==tm.tm_mon+1  && Q[j].Years==tm.tm_year+1900)
                {
                    max=Q[j].prix_TTC;
                }
        }
    //transferer le prix TTC vers prix
    printf(" %d - %d - %d \n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    printf("le max des prix des produit vendus en journee courante  Max = %.2f \n",max);
}
void MinPrixProduit(){
    //initialiser la valeur min
    float min=Q[0].prix_TTC;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    for(int j=0;j<AcheterList;j++)
        {
            if(min>Q[j].prix_TTC && Q[j].Day==tm.tm_mday && Q[j].Month==tm.tm_mon+1  && Q[j].Years==tm.tm_year+1900)
                {
                    min=Q[j].prix_TTC;
                }
        }
    printf(" %d - %d - %d \n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    printf("le Min des prix des produits vendus en journee courante Min=%.2f \n",min);
}
void AjouterProduit()
{
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
}
void AjouterPlusieurProduit()
{
            printf("veuillez saisir nombre de produits: ");
            scanf("%d",&nbr_produit);
            for(i=total_produit;i<nbr_produit+total_produit;i++)
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
}