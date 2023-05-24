// Andrew Van Siclen
// COP 3502
// 12/1/21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer{
    int arrivalTime;
    char name[21];
    char prefSylist[21];
    int loyaltyPoints;
    int time;
}customer;

typedef struct stylist{
    char styName[21];
    customer **stylistLine;
    int size;
    int n;
    customer *curCustomer;
    int timeFinished;
}stylist;

int compare(customer *a, customer *b);
void initialize(stylist *styPtr);
void insertToHeap(stylist *styPtr, customer *a);
void perkUp(stylist *styPtr,int i);
void perkDown(stylist *styPtr, int i);
void swap(customer **a, customer **b);
void doubleSize(stylist *styPtr);
void initCustomerArray(customer **customerArray,int j);

int main(void){
    // Declare variables, scan in num customers and stylists
    int numCustomers = 0, numStylists = 0;

    scanf("%d %d", &numCustomers, &numStylists);
    stylist *stylistArray[10];
    // Allocate memory for information about each customer
    customer **customerArray= calloc(numCustomers,sizeof(customer*));

    // Read in all customers and stylists
    for(int i = 0; i < numStylists; i++){
        initialize(&stylistArray[i]);
    }

    for(int j = 0; j < numCustomers; j++){
        initCustomerArray(customerArray,j);
        printf("%s\n",customerArray[j]->name);
    }

    return 0;
}

void initCustomerArray(customer **customerArray,int j){
    // Get info about each customer
    customer *curCustomer= malloc(sizeof(customer)*10);
    scanf("%d %s %s %d %d",&curCustomer->arrivalTime, curCustomer->name,curCustomer->prefSylist, &curCustomer->loyaltyPoints, &curCustomer->time);

    customerArray[j]=curCustomer;
}

void initialize(stylist *styPtr){
    // Initialize each stylist to prep for later
    scanf("%s",styPtr->styName);
    styPtr->stylistLine = malloc(sizeof(customer*));
    styPtr->stylistLine[0] = NULL;
    styPtr->n = 0;
    styPtr->size = 1;
    styPtr->curCustomer = NULL;
}

int compare(customer *a, customer *b){
    // Loyalty point comparison, return the difference
    if (a->loyaltyPoints != b->loyaltyPoints){
        return a->loyaltyPoints - b->loyaltyPoints;
    }
    // Alphabetical check
    return strcmp(a->name,b->name);
}

void insertToHeap(stylist *styPtr, customer *a){
    // Sylist line addition
    styPtr->n++;
    // If the line increases we need more space
    if(styPtr->n >= styPtr->size){
        doubleSize(styPtr);
    }
    // add the customer to the line
    styPtr->stylistLine[styPtr->n] = a;
    // Percolate up the heappp
    perkUp(styPtr,styPtr->n);
}

void doubleSize(stylist *styPtr){
    
    // Needed more space for customers so we double the heap array
    styPtr->stylistLine = realloc(styPtr->stylistLine, styPtr->size * 2);
    styPtr->size = styPtr->size * 2;
    
    // Set the extras to NULL
    for(int i = styPtr->n + 1; i < styPtr->size - 1; i++){
        styPtr->stylistLine[i] = NULL;
    }
}

void perkUp(stylist *styPtr,int i){
    // Basecase
    if (i == 1) return;
    
    int perkIndex = i/2;
    
    // Loyalty point swaps
    if (compare(styPtr->stylistLine[i],styPtr->stylistLine[perkIndex]) < 0){
        swap(&styPtr->stylistLine[i],&styPtr->stylistLine[perkIndex]);
        perkUp(styPtr,perkIndex);
    }
}

void perkDown(stylist *styPtr, int i){
    // This check if leaf node
    if (2 * i > styPtr->n) return;

    // Only left child
    if (2 * i == styPtr->n){
        if (compare(styPtr->stylistLine[(2*i)],styPtr->stylistLine[i]) < 0)
            swap(&styPtr->stylistLine[(2*i)],&styPtr->stylistLine[i]);
            return;
    }
  // COmpare then choose which will have prio
    int swapIndex = compare(styPtr->stylistLine[(i * 2)], styPtr->stylistLine[(i*2)+1]) < 0 ? (2*i) : (2*i)+1;
}

// Swap the customers
void swap(customer **a, customer **b){
  customer *tmp = *a;
  *a = *b;
  *b = *a;
}
