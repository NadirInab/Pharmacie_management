#define length 20 


// product model . 
typedef struct {
    char id[10] ;
    char name[10] ;
    int quantity ;
    float price ;
} Product ;

// product data :

Product Info[length] ;
int numberOfProduct ;
int products = 0 ;