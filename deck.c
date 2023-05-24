//
// animals.c
//
// Andrew Van Siclen
//
// Sept. 6, 2021
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
     char firstanimal[21];
     scanf("%s", firstanimal);
     char flast = firstanimal[strlen(firstanimal)-1];
     char temp[21];
     int numWords = 0;

     scanf("%d", &numWords);
    if (numWords <= 0 || numWords >= 100000){
        return 0;
    }
     char **strings = malloc(sizeof(char*)* numWords);

     for(int i = 0; i < numWords; i++)
     {
         scanf("%s", temp);
         int len = strlen(temp);
         strings[i] = malloc(sizeof(char)*(len + 1));

         strcpy(strings[i], temp);
              
      }
    
    int letter_freq[26]= {0};

        for(int i = 0; i < numWords; i++)
        {

            int len = strlen(strings[i]);
           
                if(strings[i][0])
                {
                    letter_freq[(strings[i][0]) - 'a'] +=1;
                }
            
        }
    if (letter_freq[flast - 'a'] == 0)
    {
        printf("?");
        return 0;
    }
    char solution[21];
    int found = 0;
    for(int i = 0; i < numWords; i++)
    {
        char lastLetter = strings[i][strlen(strings[i])-1];
        if (strings[i][0] == flast){
            strcpy(solution, strings[i]);
        }
        if (letter_freq[lastLetter - 'a'] >= 1){
            break;
        }
    }
    if (found == 0){
        printf("%s", solution);
    }
    else
    {
        printf("%s!", solution);
    }
   

    
    for(int i = 0; i < numWords; i++)
    {
        free(strings[i]);
    }
    free(strings);


    return 0;
}

