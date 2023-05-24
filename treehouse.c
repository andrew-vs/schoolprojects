//
//  main.c
//  treehouse
//
//  Created by Andrew Van Siclen on 9/23/21.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Max and Min coordinates
#define MAX 10000
#define MIN -10000
#define SIZE 16 // n = 8 takes a short amount of time

// Storing distances between trees
double distance[SIZE][SIZE];

// A struct for storing the x and y value of each tree
typedef struct coords{
    int x;
    int y;
} coords;

// Functions for distance calcs, permutation, making everything 0, freeing coordslist
void preComp(int trees, coords** coordslist);
double distanceCalc(coords tree1, coords tree2);
double perm(int array[], int trees, int k, int used[]);
double getDist(int *array, int trees);
void init(double distance[][SIZE], int size, int value);
void freeCoords(coords** coordslist, int trees);

int main() {
    
    // Setting up loops based off how many cases and trees
    int cases = 0;
    scanf("%d", &cases);
    if (cases > 25){
        return 0;
    }
    
    for (int i = 0; i < cases; i++){
        
        // 2n Trees
        int trees = 0, n = 0;
        scanf("%d", &n);
        if (n > 8){
            return 0;
        }
        trees = n*2;
        
        // Initializing distance array to 0
        init(distance, SIZE, 0);
        
        // Declaring the 2d array of structs of coordinates
        coords **coordslist = malloc(sizeof(coords) * trees);
        
        // Reading in every tree coordinate
        for (int j = 0; j < trees; j++){
            
            coords *coords = malloc(sizeof(coords));
            
            scanf("%d %d", &coords->x, &coords->y);
            
            coordslist[j] = coords;
        }
        
        // Filling out distance[i][j]
        preComp(trees, coordslist);
        
        // Brute force time
        int used[SIZE];
        for (int i = 0; i < SIZE; i++){
            used[i] = 0;
        }
        int order[SIZE];
        // Every valid non repeat permutation starts with 0
        order[0] = 0;
        // Rounding to 3 and outputting answer, permutations starting at index 1
        printf("%.3f\n", perm(order, trees, 1, used));
        
        freeCoords(coordslist, trees);
    }
    return 0;
}
// End of main

void init(double distance[][SIZE], int size, int value) {
    for (int i=0; i<size; i++)
        for (int j=0; j<SIZE; j++)
            distance[i][j] = value;
}

void preComp(int trees, coords** coordslist)
{
  for(int i = 0; i < trees; i++)
  {
    for(int j = 0; j < trees; j++)
    {
        distance[i][j] = distanceCalc(*coordslist[i],*coordslist[j]);
    }
  }
}

// Calculating distance using sqrt from math.h
double distanceCalc(coords tree1, coords tree2)
{
    return sqrt ((tree1.x - tree2.x)*(tree1.x - tree2.x) +
               (tree1.y - tree2.y)*(tree1.y - tree2.y)
  );

}

// Permutating and optimizing for n = 6
double perm(int array[], int trees, int k, int used[]){
    
    // Done permutating?
    if (k == trees){
        return getDist(array, trees);
    }
    
    double res = 100000; // Overwritten later
    // Even cases
    if (k % 2 == 0){
        for(int i = array[k-2] + 1; i < trees; i++){
            
            if (used[i]) continue;
            array[k] = i;
            used[i] = 1;
            
            double thisRes = perm(array, trees, k+1, used);
            if (thisRes < res){
                res = thisRes;
            }
            
            used[i] = 0;
        }
    }
    // Odd cases
    else{
        for (int i = array[k-1] + 1; i < trees; i++){
            if (used[i]) continue;
            array[k] = i;
            used[i] = 1;
            
            double thisRes = perm(array, trees, k+1, used);
            if (thisRes < res){
                res = thisRes;
            }
            
            used[i] = 0;
        }
    }
    return res;
}

// Updating res to return it because thats the output
double getDist(int *array, int trees){
    
    double res = 0;

    // Adding the solution up to return total distance
    for(int i = 0; i < trees-1; i+=2){
            res += distance[array[i]][array[i+1]];
    }
        return res;
    
}
    
void freeCoords(coords** coordslist, int trees){
    for (int i = 0; i < trees; i++){
        free(coordslist[i]);
    }
    free(coordslist);
}

