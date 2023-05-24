//
//  main.c
//  lottery
//
//  Created by Andrew Van Siclen on 10/5/21.
//

#include <stdio.h>
#include <stdlib.h>

// Node on linked list
struct node {
    int data;
    struct node *next;
};

// Functions for create each group linked list, skipping function, delnode and free
struct node* createList(struct node *front, int data);
struct node* createGroup(int numPeople);
int skipTime(struct node *front,int skip, int Thresh, int numPeople);
struct node* delete(struct node *front, struct node* temp);
void freeFront(struct node *front);

int main(void)
{
    
    // Initialize all input variables and results
    int cases, groups, people, skip, threshold, winner, groupWinner, groupNum = 0;
    struct node* front = NULL;
    
    // Will be reset by the new low of each group
    winner = 100000;
    
    scanf("%d", &cases);
    if(cases > 25){
        return 0;
    }
    
    // Getting cases and groups
    for(int i = 0; i < cases; i++){
        
        scanf("%d", &groups);
        if(groups > 10){
            return 0;
        }
        
        for(int j = 0; j < groups; j++)
        {
            // Getting people, skip, threshold and creating a pointer to the front of the
            // group list
            scanf("%d %d %d", &people, &skip, &threshold);
            if(people < 2 || people > 100000 || skip < 0 || skip > people || threshold < 1 || threshold > people){
                return 0;
            }
            struct node* front = createGroup(people);
            printf("Group# %d\n", j+1);
            groupWinner = skipTime(front, skip, threshold, people);

            // Checking if the group winner beats the current winner
            if(groupWinner < winner){
                winner = groupWinner;
                groupNum = j+1;
            }

        }
        
        // Ta-da
        printf("Lottery winner is person %d from group %d.\n", winner, groupNum);
        
        // For the next case these will be 0/reset
        groupNum = 0;
        winner = 100000;
    
        freeFront(front);
    }
    
    return 0;
    
} // End of main

// For every group create a linked list the amount of people long
struct node* createGroup(int people){
    
    struct node* temp = NULL;
        // Adding 1 then 2 then 3 etc
        for(int i = 0; i < people; i++){
            temp = createList(temp,i+1);
        }
    return temp;
}

// Add to back of linked list, then when you reach the end point to head (circular)
struct node* createList(struct node* front, int data){
    
    // One to point to head, the other to go through the list
    struct node *iter, *temp;
    
    // Adding 1 then 2 etc
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    
    // If it's empty, have it point to itself
    if(front == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = front;
        iter = front;
        
        // Go through list
        while(iter ->next != front){
            iter = iter->next;
        }
        // When it hits the end, the end points to the front
        iter->next = temp;
        return front;
    }
}

// Move to point before node to delete, check if its head, then connect to the node 2 after
// and delete the node skip got us to.
int skipTime(struct node* front, int skip, int threshold, int people){
    
    if(front == NULL){
        return 0;
    }
    
    // A pointer to the front and a pointer to edit
    struct node* temp;
    temp = front;
    
    while (temp->next != front){
        temp = temp->next;
    }
    
    // Amount of times we skip someone is people-threshold, or this comparison
    while(people > threshold){
        
        // Skip over __ spaces
        for(int i = 0; i < skip; i++){
        temp = temp->next;
        }
        
        // If we are about to delete front make front the next node over
        if(temp->next == front){
            front = front->next;
        }
        temp = delete(front,temp);
        // Num of people went down due to skipping someone
        people--;
    }
    
    return front->data; // For comparison in main
}

// Make the node before deletion connect to the node after deletion
struct node* delete(struct node* front, struct node* temp){
    
    // The node to be deleted, so this delNode->next is 2 away from temp->next
    struct node* delNode;
    delNode = temp->next;
    
    //Making the bridge
    temp->next = delNode->next;
    printf("%d\n", delNode->data);
    free(delNode);
    return temp;
}

// Freeing memory
void freeFront(struct node* front){

    if(front == NULL){
        return;
    }
    
    // Freeing front linked list
    if(front == front->next){
        free(front);
        return;
    }
    
    struct node* temp = front;
    temp = temp->next;
    
    // Freeing each group list itself
    while(temp != NULL)
    {
        struct node* freeP = temp;
        temp = temp->next;
        free(freeP);
    }
    free(temp);
}
