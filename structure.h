#define length 20 

// product model . 
typedef struct {
    char id[10] ;
    char name[10] ;
    int quantity ;
    float price ;
} Product ;

// struct to save the purchase data .
typedef struct 
{
    char id[10] ;
    char name[10];
    int quantity;
    float price ;
    char productBuyTime[50] ;
} PurchaseData; 

// product data :
//,{"p1","Ecotrin.",15, 16.00 }
Product Info[length] = {
    {"p0","Aspirine",12, 10.00 } 
} ;
int numberOfProduct ;
int products = 1 ;
int numberOfsales = 0 ;
char productBuyTime[50] ;

PurchaseData thePurchaseData[length] ;