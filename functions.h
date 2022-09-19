#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h" 

void theMain() ;
void addProduct() ;
void addMultiProduct() ;
void return_or_exit() ;
void displaying() ;
void searchByCode() ;
void searchByQuantity() ;
void sortAllProducts();
void sortByName() ;
void sortByPrice() ;
void stockAvailibility() ;
void purchaseProduct() ;
void feedStock() ;

void theMain(){
    int userChoice  ;
    here:
do
{
    system("cls") ;
    printf("\t\t===============================================\n ") ;
    printf("\t\t==========||Welcome to our Medicines Management|| ======== \n") ;
    printf("\t\t=============================================== \n") ;
    printf("\t\t[1]-Add new Product \n") ;
    printf("\t\t[2]-Add multiple Products :\n ") ;
    printf("\t\t[3]-Display all the product :\n ") ;
    printf("\t\t[4]-Purchase a product :\n ") ;
    printf("\t\t[5]-Stock availibility :\n ") ;
    printf("\t\t[6]- getttetetFeed stock :\n ") ;
    printf("\t\tchoose : ") ;

    scanf("%d",&userChoice);

    switch (userChoice)
    {
    case 1:
        addProduct() ;
        break;
    case 2:
        addMultiProduct() ;
        break;
    case 3:
        displaying();
        break;
    case 4:
        purchaseProduct();
        break;
    case 5:
        stockAvailibility();
        break;
    case 6:
        feedStock();
        break;
    default : 
        theMain() ;
        break;
}
}while (userChoice < 1 || userChoice > 1);

}


void addProduct(){
        printf("\n\n=====|| Add Product Info ||===== \n\n") ;
        printf("======================================\n") ;

        printf("add Product Id : ") ;
        scanf("%s",&Info[products].id) ;
        printf("add Product Name : ") ;
        scanf("%s",&Info[products].name) ;
        printf("add the Quantity : ") ;
        scanf("%d",&Info[products].quantity) ;
        printf("add the price : ") ;
        scanf("%f",&Info[products].price) ;
       
       for (int i = 0; i < products; i++)
       {
        printf("\t\t===Your product :===== \n") ;
        printf("the product Id :%s \n ",Info[products].id) ;
        printf("the product name :%s \n",Info[products].name) ;
        printf("the product quantity :%d \n",Info[products].quantity) ;
        printf("the product price :%.2f \n",Info[products].price) ;
       }
       
        // printf("\t\t===Your product :===== \n") ;
        // printf("the product Id :%s \n ",Info[products].id) ;
        // printf("the product name :%s \n",Info[products].name) ;
        // printf("the product quantity :%d \n",Info[products].quantity) ;
        // printf("the product price :%.2f \n",Info[products].price) ;
        products++ ;
         return_or_exit() ;
}


void addMultiProduct(){
    int numberOfProduct ;
    printf("Enter the number of products to add : ") ;
    scanf("%d",&numberOfProduct) ;
    //===============|| Adding the products ||=============// 
    for (int i = 0; i < numberOfProduct; i++)
    {
        printf("\n\n =====Add Product Info :===== \n\n") ;
        printf("add Product Id : ") ;
        scanf("%s",&Info[products].id) ;
        printf("add Product Name : ") ;
        scanf("%s",&Info[products].name) ;
        printf("add the Quantity : ") ;
        scanf("%d",&Info[products].quantity) ;
        printf("add the price : ") ;
        scanf("%f",&Info[products].price) ;
        products++ ;
    }
    system("cls");
    printf("\n\n ====| Products data has been added successfully :\n\n") ;
    printf("\t\t======Your product       :======= \n") ;

     // =========|| displaying the products ||=======
    for (int i = 0; i < numberOfProduct; i++)
    {
        printf("\nthe product Id       :%s  ",Info[i].id) ;
        printf("\nthe product name     :%s ",Info[i].name) ;
        printf("\nthe product quantity :%d ",Info[i].quantity) ;
        printf("\nthe product price    :%.2f Dhs \n\n",Info[i].price) ;
    }

    return_or_exit() ;
}

void return_or_exit(){
  int choice;
do {
    ther :
    printf("\n\n==> 1- Return to the menu .");
    printf("\n\n==> 2- Exit .\n");
    printf("\n\n=====>Your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : theMain();
             break;
        case 2 : exit(0); 
            break;
        default : printf("\n\n invalide choice . Try Again ");
        goto ther;
    }
    } while (choice < 1 || choice > 2 );
}


void displaying(){
  int userChoice;
  system("cls");
  printf("\n");
  printf("List des produits par ordre :\n");
  printf("\n\n");
  printf("[1]- search by Code.\n");
  printf("[2] - search by Quantity.\n");
  printf("[3] - Sort the products.\n");
  printf("[4] - situation of the stock.\n");
  // printf("[5] - Feed the stock.\n");
  // printf("[6] - delete by code.\n\n");
  // printf("[7] - purchase data.\n\n");
  printf("Votre choix : ");
  scanf("%d", &userChoice);
  switch (userChoice)
  {
  case 1:
    searchByCode();
    break;
  case 2:
    searchByQuantity();
    break;
  case 3:
    sortAllProducts();
    break;
  case 4:  
    // Etat_du_stock();
    break;
  // case 5:
  //   Feed_stock();
  //   break;
  // case 6:
  //   deleteProductByCode();
  //   break;
  // case 7:
  //   dataOfSell();
  //   break;
  default:
    displaying();
  }
}


void searchByCode(){
     //  system("cls");
     char productId[2] ;
     printf("\n\n");
     printf("Veuilez saisir le Code du produit : ");
     scanf("%s", &productId);
     printf("\n\n");

     for (int i = 0; i <products; i++)
     {
         if (strncmp(Info[i].id, productId,2) == 0)
         {
            printf("\n\n");
            printf("Code     : %s\n", Info[i].id);
            printf("Nom      : %s\n", Info[i].name);
            printf("Quantite : %d\n", Info[i].quantity);
            printf("Prix     : %.2f Dhs\n", Info[i].price);
            printf("\n");
         } 
      }
      printf("\n\n");
      return_or_exit();
}


void searchByQuantity(){
     //  system("cls");
     int productQuantity;
     printf("\n\n");
     printf("Veuilez saisir le quantite du produit : ");
     scanf("%d", &productQuantity);
     printf("\n\n");

     for (int i = 0; i < products; i++)
     {
         if (Info[i].quantity == productQuantity)
         {
            printf("\n\n");
            printf("Code     : %s\n", Info[i].id);
            printf("Nom      : %s\n", Info[i].name);
            printf("Quantite : %d\n", Info[i].quantity);
            printf("Prix     : %.2f Dhs\n", Info[i].price);
            printf("\n");
         } 
      }
      printf("\n\n");

      return_or_exit();
}

void sortAllProducts(){
  int userChoice;
  system("cls");
  printf("\n");
  printf("Sort all the products :\n");
  printf("\n\n");
  printf("[1] - Sort By Name.\n");
  printf("[2] - Sort By price.\n\n");
  printf("Choose  : ");
  scanf("%d", &userChoice);

  switch (userChoice)
  {
  case 1:
    sortByName();
        break;
  case 2:
    sortByPrice();
        break;
  default:  
    displaying() ;
        break ;
  }
  // for (int i = 0; i < nbProduit; i++)
  // {
  //    float prix_TTC = (produit[i].Prix*0.15)+produit[i].Prix;

  //    printf("\n--> Nom de Produit : %s.\n  - Prix      :  %.2f MAD.\n  - Prix TTC : %.2f MAD.\n\n",produit[i].Nom, produit[i].Prix, prix_TTC);
  //    }
    return_or_exit();
}

void sortByName(){

 Product extrenal ;
 for (int i = 0; i < products; i++){
 for (int k = 0; k < products; k++)
 {
  for (int j = k + 1; j < products; j++)
  {
    if (strcmp(Info[k].name,  Info[j].name) > 0)
    {
      extrenal = Info[k];
      Info[k] = Info[j];
      Info[j] = extrenal;
    }
  }
 }
     float ttcPrice = (Info[i].price*0.15)+Info[i].price;
    //  printf(" Info N*%d \n", i + 1);
      printf("\n");
      printf("==> product's name  : %s\n", Info[i].name);
      printf("==> Product's price : %.2f MAD\n", Info[i].price);
      printf("==> ttc price       : %.2f MAD\n", ttcPrice);
      printf("\n");

    //  printf("\n--> Nom de Produit : %s.\n  - Prix      :  %.2f MAD.\n  - Prix TTC : %.2f MAD.\n\n",produit[i].Nom, produit[i].Prix, prix_TTC);
     }
  return_or_exit();

}


void sortByPrice(){
  Product external;
  
 for (int i = 0; i < products; i++){
 for (int r = 0; r < products; r++)
 {
  for (int j = r + 1; j < products; j++)
  {
    if (Info[r].price < Info[j].price)
    {
      external = Info[r];
      Info[r] = Info[j];
      Info[j] = external;
    }
  }
 }
     float prix_TTC = (Info[i].price*0.15)+Info[i].price;
    //  printf(" produit N*%d \n", i + 1);
      printf("\n");
      printf("==> Product's name :  %s\n", Info[i].name);
      printf("==> Product's price:  %.2f MAD\n", Info[i].price);
      printf("==> ttc price      : %.2f MAD\n", prix_TTC);
      printf("\n");

    //  printf("\n--> Nom de Produit : %s.\n  - Prix      :  %.2f MAD.\n  - Prix TTC : %.2f MAD.\n\n",produit[i].Nom, produit[i].Prix, prix_TTC);
     }
  return_or_exit();
}


void  stockAvailibility(){
  for(int i = 0; i < products; i++)
  {
    if (Info[i].quantity < 3)
    {
      printf("\n\n");
            printf("Product Id    : %s\n", Info[i].id);
            printf("Product Name      : %s\n", Info[i].name);
            printf("Product quantity : %d\n", Info[i].quantity);
            printf("Product price     : %.2f Dhs\n", Info[i].price);
            printf("\n");
    }
    
  }
  return_or_exit();
}

void purchaseProduct(){
char productId[10];
int wantedQuantity;
     system("cls");
     printf("\n\n");

     printf("Enter the product Code : ");
     scanf("%s", productId);

     printf("\n");
     printf("enter the wanted quantity : ");
     scanf("%d", &wantedQuantity);
     
     system("cls");
     printf("\n\n");
     printf("==> The product code     : %s\n", productId);
     printf("==> The wanted quantity  : %d \n\n", wantedQuantity);

     for (int i = 0; i < products; i++)
     {
         if (strcmp(Info[i].id, productId) == 0)
         {

          printf("The Former quantity  : %d \n", Info[i].quantity);
          Info[i].quantity = Info[i].quantity - wantedQuantity;
          printf("The actual quantity : %d\n", Info[i].quantity);
          } 
      }
      printf("\n\n");

      return_or_exit();
}

void feedStock(){
  char productId[2] ;
  int feedQuantity ;
  printf("enter the wanted id : \n\n") ;
  scanf("%s",&productId) ;
  printf("Quantity to be added \n\n") ;
  scanf("%d",&feedQuantity) ;
  for(int i = 0 ; i < products ;i++){
    if (strcmp(Info[i].id, productId)==0){
      Info[i].quantity += feedQuantity ;
      printf("%s",Info[i].name) ;
      printf("%s",Info[i].quantity) ;
    }else{
      printf("the product id doesn't exist") ;
    }
  } 
}