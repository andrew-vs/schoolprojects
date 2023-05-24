//
//  main.c
//  smoothies
//
//  Created by Andrew Van Siclen on 9/10/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defining max values for each input
#define MAXING 100000
#define MAXRECP 100000
#define MAXPARTS 1000
#define MAXSTORES 100
#define MAXWEIGHT 1000

//declaring the structs of each recipe and the item list of that recipe
typedef struct item {
 int itemID;
 int numParts;
} item;

typedef struct recipe {
 int numItems;
 item* itemList;
 int totalParts;
} recipe;

//functions for reading ingredients and recipes, calculating the amount to be ordered, freeing each 2d array
char** readIngredients(int numIng);

recipe** readallRecipes(int numRecp);

recipe* readRecipe(int numItems);

double* calculateOrder(int r, int numRecp, recipe** smoothieList, int numIng);

void printOrder(char** ingredients, double* amtOfEachItem, int numIng);

void freeIngredients(char** ingredients, int numIng);

void freeRecipes(recipe** smoothieList, int numRecp);

int main(void) {
    
    //getting number of Ingredients and kicking us out if its too much
    int numIng = 0;
    scanf("%d", &numIng);
    if (numIng > MAXING){
        return 0;
    }
    //making the array to be used by functions later
    char** ingredients;
    ingredients = readIngredients(numIng);
    int numRecp = 0;
    
    //getting number of recipes, if its too much, booted
    scanf("%d", &numRecp);
    if (numRecp > MAXRECP){
        return 0;
    }
    
    //making the list of all smoothie recipes with this array of structs
    recipe **smoothieList = calloc(sizeof(recipe*), numRecp);
    smoothieList = readallRecipes(numRecp);
    
    //getting number of stores and leaving if its too big
    int numStores = 0;
    scanf("%d", &numStores);
    if (numStores > MAXSTORES){
        return 0;
    }
    
    //beginning of calculations
    //a loop to calculate what each store needs, 1 store per loop
    for (int i = 0; i < numStores; i++){
        
        //getting the amount of smoothies the current store offers
        int r = 0; //amount of smoothies a store offers
        printf("Store #%d:\n", i+1);
        scanf("%d", &r);
        
        //making the array of every item and how much is needed, then printing
        double* orderList = malloc(sizeof(double) * numIng);
        orderList = calculateOrder(r, numRecp, smoothieList, numIng);
        printOrder(ingredients, orderList, numIng);
    }
   
    //free da memory
    freeIngredients(ingredients, numIng);

    freeRecipes(smoothieList, numRecp);
    
    return 0;
    //end of main
}

//just a simple function to get all the names similar to alphabetanimals
char** readIngredients(int numIng){
    
    char **ingredients = malloc(sizeof(char *)* numIng);
    
    char temp[21];

    for (int i = 0; i < numIng; i++){
        
        scanf("%s", temp);
        int len = strlen(temp);
        if (temp[0] == '\0' || len < 1 || len > 20){
            return 0;
        }
        
        ingredients[i] = malloc(sizeof(char)*(len + 1));
        
        strcpy(ingredients[i], temp);
    }
    //returning the whole 2d array of all ingredients
    return ingredients;
}

//taking in the amount of recipes then looping through that amount
recipe** readallRecipes(int numRecp){
    
    recipe **smoothieList = calloc(sizeof(recipe*), numRecp);
    
    for (int i = 0; i < numRecp; i++){
        int numItems = 0; //resetting the number of items for each recipe
        
        scanf("%d", &numItems);
        //going to our other function to get itemID and number of items
        smoothieList[i] = readRecipe(numItems);
    }
    
    return smoothieList;
}

//this function is to get the itemID and how much of that item
recipe* readRecipe(int numItems){
   
    recipe *smoothie = malloc(sizeof(recipe));
    
    smoothie->itemList = malloc(sizeof(item)* numItems);
    
        //from the previous function, now we just make it the smoothies item amount
        smoothie->numItems = numItems;
        
        smoothie->totalParts = 0;
    
    //loop to get the 2 numbers
    for (int i = 0; i < smoothie->numItems; i++){
        
        scanf("%d%d", &smoothie->itemList[i].itemID, &smoothie->itemList[i].numParts);
        
        //adding to the totalparts amount from the last loop
        smoothie->totalParts += smoothie->itemList[i].numParts;
    }

    return smoothie;
    
}

//basically calculating the frequency array
double* calculateOrder(int r, int numRecp, recipe** smoothieList, int numIng){
    
    double* amtOfEachItem = malloc(sizeof(double) * numIng);
    for(int z = 0; z < numIng; z++){
        //setting everything inside to 0 to start
        amtOfEachItem[z] = 0;
    }
    
    //getting the number and then the weight
    for (int i = 0; i < r; i++){
        int smoothieNo = 0;
        int smoothieWeight = 0;
        scanf("%d%d", &smoothieNo, &smoothieWeight);
        if (smoothieNo > numRecp || smoothieWeight > MAXWEIGHT){
            return 0;
        }
        
        //the coefficient is the inputted weight divided by how many items are in ONE smoothie
        double coeff = 0;
        coeff = smoothieWeight/(double)smoothieList[smoothieNo]->totalParts;
        
        //this is how I got Weight_To_Order, its the coefficent times how many parts of that one ingredient
        for (int j = 0; j < smoothieList[smoothieNo]->numItems; j++){
            amtOfEachItem[smoothieList[smoothieNo]->itemList[j].itemID] += (smoothieList[smoothieNo]->itemList[j].numParts*coeff);
        }
    
    }
    
    //returning all the Weights to order for the one store
    return amtOfEachItem;

}

//printing the results
void printOrder(char** ingredients, double* orderList, int numIng){
    
    //loop through every since ingredient, but if its 0 parts then just dont print it
    for (int p = 0; p < numIng; p++){
        if(orderList[p] > 0){
            printf("%s %.6f\n", ingredients[p], orderList[p]);
            }
    }
}

//freeing the ingredients
void freeIngredients(char** ingredients, int numIng){
    for (int i = 0; i < numIng; i++){
        free(ingredients[i]);
    }
    free(ingredients);
}

//freeing the structs of recipes
void freeRecipes(recipe** smoothieList, int numRecp){
    for (int i = 0; i < numRecp; i++){
        free(smoothieList[i]);
    }
    free(smoothieList);
}

 
