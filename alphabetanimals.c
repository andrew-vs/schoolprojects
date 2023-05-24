//
//  main.c
//  animalsretry
//
//  Created by Andrew Van Siclen on 9/8/21.
//

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

int duplicate (char** animals, int numAnimals, int i);

int main(void) {
    
    char fanimal[21];
    scanf("%s", fanimal);
    int flen = strlen(fanimal);
    if (fanimal[0] == '\0' || flen < 1 || flen > 20 ){
        printf("?");
        return 0;
    }
    char flast = fanimal[strlen(fanimal)-1];
    
    int numAnimals = 0;
    scanf("%d", &numAnimals);
    if (numAnimals > 100000 || numAnimals <= 0){
        printf("?");
        return 0;
    }
    
    char **animals = malloc(sizeof(char*)* numAnimals);
   
    
    char temp[21];
    
    for (int i = 0; i < numAnimals; i++){
        
        scanf("%s", temp);
        int len = strlen(temp);
        
        if (temp[0] == '\0' || len < 1 || flen > 20 || strcmp(temp, fanimal) == 0){
            printf("?");
            return 0;
        }
        
        animals[i] = malloc(sizeof(char)*(len + 1));
        
        strcpy(animals[i], temp);
        
        
    }
    
    for (int i = 0; i < numAnimals; i++){
        if(duplicate(animals, numAnimals, i) == 1){
            printf("?");
            return 0;
        }
    }
   
    
    int first_freq[26];
    for (int i = 0; i < 26; i++){
        first_freq[i] = 0;
    }
    for (int i = 0; i < numAnimals; i++){
        first_freq[(animals[i][0]) - 'a'] += 1;
    }
    
    if (first_freq [flast - 'a'] == 0){
        printf("?");
        return 0;
    }
    
    for (int i = 0; i < numAnimals; i++){
        
        char lastLetter = animals[i][strlen(animals[i]) - 1];
        
        if (lastLetter == animals[i][0] && flast == animals[i][0]){
            if(first_freq[lastLetter - 'a'] <= 1){
                printf("%s!", animals[i]);
                return 0;
            }
        }
        
        if(first_freq[lastLetter - 'a'] == 0 && flast == animals[i][0]){
            printf("%s!", animals[i]);
            return 0;
        }
    }
    
    for (int i = 0; i < numAnimals; i++){
        
        char lastLetter = animals[i][strlen(animals[i]) - 1];
        if(first_freq[lastLetter - 'a'] > 0){
            if (first_freq[lastLetter - 'a'] > 0 && flast == animals[i][0]){
                printf("%s", animals[i]);
                return 0;
            }
            
        }
        
    }
    
    for(int i = 0; i < numAnimals; i++)
    {
        free(animals[i]);
    }
    free(animals);
    
}


int duplicate(char** animals, int numAnimals, int i){
        int k = 0;
    char temp[21];
    strcpy(temp, animals[i]);
    for(int q = 0; q < numAnimals; q++){
        if (strcmp(temp, animals[q]) == 0){
            k++;
        }
        if (k > 1){
                return 1;
                }
    }
    return 0;
}
