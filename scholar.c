//
//  main.c
//  scholar
//
//  Created by Andrew Van Siclen on 10/28/21.
//

#include <stdio.h>
#include <stdlib.h>

void quicksort(int* pageArray, int low, int high);
int partition(int* pageArray, int low, int high);
void swap(int *a, int *b);
int sorted(int values[], int low, int high);
int bookCount(int* pageArray, long long maxPages, int totalBooks);

int main() {
    
    int cases = 0;
    scanf("%d", &cases);
    if (cases > 25) return 0;
    
    for (int i = 0; i < cases; i++){
        
        // Store the pages as a long long because the max it can be is very large
        int totalBooks = 0;
        long long maxPages = 0;
        scanf("%d %lld", &totalBooks, &maxPages);
        // Input restrictions
        if (totalBooks > 100000 || maxPages > 100000000000000) return 0;
        
        // Store in a dynamically allocated array
        int* pageArray = malloc(sizeof(int)*totalBooks);
        // Get each number of pages
        for (int j = 0; j < totalBooks; j++){
            scanf("%d", &pageArray[j]);
            if (pageArray[j] > 1000000000) return 0;
            
        }
        
        // Sort the array
        quicksort(pageArray, 0, totalBooks-1);
        
        // Get the result
        int result = bookCount(pageArray, maxPages, totalBooks);
        printf("%d\n", result);
        
        free(pageArray);
    }
    return 0;
}

// Check if the array is already sorted
int sorted(int values[], int low, int high) {


    for (int i = low; i < high-1; i++){
        
        if (values[i] > values[i+1]){
            
            return 0;
        }
    }
    return 1;
}

void quicksort(int* pageArray, int low, int high) {

    // List already sorted
    if (sorted(pageArray, low, high)) return;

    // Split the numbers, sort each side
    int split = partition(pageArray,low,high);
    quicksort(pageArray,low,split-1);
    quicksort(pageArray,split+1,high);
}

int partition(int* pageArray, int low, int high) {

    int i;
    
    // Put random value in low index
    i = low + rand()%(high-low+1);
    swap(&pageArray[low], &pageArray[i]);

    // Save the spot of the lowest index
    int lowpos;
    lowpos = low;

    low++;

    // The counters cant cross this way.
    while (low <= high) {
        
        // Find value thats too high
        while (low <= high && pageArray[low] <= pageArray[lowpos]){
            low++;
        }

        // Fnd value thats too small
        while (high >= low && pageArray[high] > pageArray[lowpos]){
            high--;
        }
        // Swap the value thats too high and the value thats too low
        if (low < high){
            swap(&pageArray[low], &pageArray[high]);
        }
    }

    // Put the partition element back
    swap(&pageArray[lowpos], &pageArray[high]);

    return high;
}

// Swap the values that are sent in to the function
void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
}

// Count how many books we can read
int bookCount(int* pageArray, long long maxPages, int totalBooks){
    
    int howMany = 0;
    long long pageCount = 0;
   
    // Go through each book and add to the running page count
    for(int i = 0; i < totalBooks; i++){
        
        pageCount += pageArray[i];
        
        if(pageCount > maxPages){
            return howMany;
        }
        
        // If we get here, it means the book doesnt make us go over the page limit
        howMany++;
    }

    return howMany;

}
