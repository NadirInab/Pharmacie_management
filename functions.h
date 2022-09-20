#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
void deleteProduct() ;
void saleData() ;

void theMain(){
    int userChoice  ;
    here:
do
{
    system("cls") ;
    printf("\t\t===============================================\n ") ;
    printf("\t\t==========||Welcome to our Medicines Management|| ======== \n") ;
    printf("\t\t=============================================== \n") ;
    printf("\t\t==|[1]-Add new Product \n") ;
    printf("\t\t==|[2]-Add multiple Products :\n ") ;
    printf("\t\t==|[3]-Display all the product :\n ") ;
    printf("\t\t==|[4]-Purchase a product :\n ") ;
    printf("\t\t==|[5]-Delete a product :\n ") ;
    printf("\t\t==|[6]-Sale's Data :\n ") ;
    printf("\t\t==|user choice : ") ;
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
        deleteProduct();
        break;
    case 6:
        saleData();
        break;
    case 7 : 
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
        printf("the product Id :%s \n ",Info[i].id) ;
        printf("the product name :%s \n",Info[i].name) ;
        printf("the product quantity :%d \n",Info[i].quantity) ;
        printf("the product price :%.2f \n",Info[i].price) ;
       }
        products++ ;
         return_or_exit() ;
}
//===================================================================================================
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
    for (int i = 0; i < products; i++)
    {
        printf("\nthe product Id       :%s  ",Info[i].id) ;
        printf("\nthe product name     :%s ",Info[i].name) ;
        printf("\nthe product quantity :%d ",Info[i].quantity) ;
        printf("\nthe product price    :%.2f Dhs \n\n",Info[i].price) ;
    }

    return_or_exit() ;
}
//=======================================================================================================
void return_or_exit(){
  int choice;
do {
    ther :
    printf("\n\n==> [1]- Return to the menu .");
    printf("\n\n==> [2]- Exit .\n");
    printf("\n\n=====>Your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : 
          theMain();
             break;
        case 2 : 
          exit(0); 
            break;
        default : printf("\n\n invalide choice . Try Again ");
        goto ther;
    }
    } while (choice < 1 || choice > 2 );
}
//==============================================================================================
void displaying(){
  int userChoice;
  system("cls");
  printf("\n");
  printf("List des produits par ordre :\n");
  printf("\n\n");
  printf("[1]-Search by Code.\n");
  printf("[2]-Search by Quantity.\n");
  printf("[3]-Sort the products.\n");
  printf("[4]-Stock availibility :\n ") ;
  printf("[5]-Feed stock :\n ") ;
  printf("[6]-Return to the main :\n ") ;
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
   stockAvailibility();
    break;
  case 5:
       feedStock();
    break;
  case 6:
       theMain();
    break;
  default:
    displaying();
  }
}
//==============================================================================================
void searchByCode(){
      // system("cls");
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
//==============================================================================================
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
//==============================================================================================
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
    return_or_exit();
}
//==============================================================================================

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
      printf("\n");
      printf("==> product's name  : %s\n", Info[i].name);
      printf("==> Product's price : %.2f MAD\n", Info[i].price);
      printf("==> ttc price       : %.2f MAD\n", ttcPrice);
      printf("\n");
     }
  return_or_exit();

}
//==============================================================================================

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
      printf("\n");
      printf("==> Product's name :  %s\n", Info[i].name);
      printf("==> Product's price:  %.2f MAD\n", Info[i].price);
      printf("==> ttc price      : %.2f MAD\n", prix_TTC);
      printf("\n");
     }
  return_or_exit();
}
//==============================================================================================
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
//==============================================================================================
/// here we buy a product .
void purchaseProduct(){
char productId[10];
int wantedQuantity;
struct tm *buyTime;
char productBuyTime[50] ;
    //  system("cls");
    printf("\n\n");
    // saving purchasing data .
    time_t purchaseTime ;
    time(&purchaseTime);
    buyTime= localtime(&purchaseTime) ;
    strftime(productBuyTime,50,"%x", buyTime);

    // end of saving purchasing data . 
    printf("Enter the product Code : ");
    scanf("%s", productId);
    printf("\n");
    printf("enter the wanted quantity : ");
    scanf("%d", &wantedQuantity);
    // pickingUp ++ ;
     system("cls");
     printf("\n\n ======================================= \n"); 
     printf("=====||Purchase Products ||======") ;
     printf("\n\n ======================================= \n"); 
     printf("==> The product code     : %s\n", productId);
     printf("==> The wanted quantity  : %d \n\n", wantedQuantity);
     for (int i = 0; i < products; i++)
     {
         if (strcmp(Info[i].id, productId) == 0)
         {
          printf("==>The Former quantity  : %d \n", Info[i].quantity);
          Info[i].quantity = Info[i].quantity - wantedQuantity;
            printf("==>The actual quantity  : %d\n", Info[i].quantity);
            strcpy(thePurchaseData[i].id,Info[i].id) ;
            strcpy(thePurchaseData[i].name,Info[i].name) ;
            thePurchaseData[i].quantity = wantedQuantity ;
            strcpy(thePurchaseData[i].productBuyTime, productBuyTime) ;
            thePurchaseData[i].price = Info[i].price ;
          } 
            printf("\t======|* * * * * *|======= \n") ;
          printf("\t======| Your Bill |=======\n") ;
          printf("\t======|* * * * * *|=======") ;
          printf("\n\t Product Id    :%s ",thePurchaseData[i].id ) ;
          printf("\n\t Product name  :%s ",thePurchaseData[i].name ) ;
          printf("\n\t ==>Date       : %s",thePurchaseData[i].productBuyTime ) ;
          printf("\n\t ==>Quantity   : %d ",thePurchaseData[i].quantity ) ;
          printf("\n\t ==>Total price: %.2f Dh",(thePurchaseData[i].price*wantedQuantity)) ;
      }
       
      pickingUp ++ ;
      printf("\n\n");
      return_or_exit();
}
//==============================================================================================
void feedStock(){
  char productId[2] ;
  int feedQuantity ;
  printf("enter the wanted id : \n\n") ;
  scanf("%s",&productId) ;
  printf("Quantity to be added \n\n") ;
  scanf("%d",&feedQuantity) ;
  for(int i = 0 ; i < products ;i++){
    if (strcmp(Info[i].id, productId)==0){
      printf("%d",Info[i].quantity) ;
      Info[i].quantity += feedQuantity ;
      printf("%s",Info[i].name) ;
      printf("%d",Info[i].quantity) ;
    }else{
      printf("the product id doesn't exist") ;
    }
  } 
}

//==============================================================================================
void deleteProduct(){
  char idToDelete[2] ;
  printf("Enter product's Id : ") ;
  scanf("%s",&idToDelete) ;
  printf("%s",idToDelete) ;
  for(int i = 0; i < products ; i++){
    if(strcmp(idToDelete,Info[i].id)==0){
        printf("here") ;
      // printf("%s \n", Info[i].id) ;
      // printf("%s",Info[i].name) ;
    }
  }
}
//==============================================================================================
void saleData(){
  // char daytoknow[50] ;
  printf("===here we are== \n") ;
  printf("Enter day :") ;
  // scanf("%s ",&daytoknow) ;
  // printf("\n %s \n",daytoknow) ;

    // for (int j = 0; j < products; j++)
    // {
    //   int totalPrice = Info[j].price*thePurchaseData[j].quantity ;
    //   printf("we sold today %s %d of %s",thePurchaseData[j].productBuyTime,totalPrice,Info[j].name) ;
    // }

} 