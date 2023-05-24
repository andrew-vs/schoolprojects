//
//  main.c
//  wordsort
//
//  Created by Andrew Van Siclen on 11/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree_node {
    char word[20];
    int query;
    int freq;
    int depth;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node* create_node(int query, char newWord[20]);
struct tree_node* insert(struct tree_node *root, struct tree_node *node, struct tree_node** structs, int i);
struct tree_node* search(struct tree_node* root, char *data);

int main() {
    
    int cases = 0;
    scanf("%d", &cases);
    if(cases>200000) return 0;
    
    struct tree_node *root=NULL, *temp_node;
    struct tree_node** structs = calloc(sizeof(structs), cases);
    int words = 0;
    for(int i = 0; i < cases; i++){
        
        int query = 0;
        char word[20];
        
        scanf("%d %s", &query, word);
        
        temp_node = create_node(query, word);
        
        if(query == 1){
            root = insert(root, temp_node, structs, i);
        }
        else if(query == 2){
            
            struct tree_node* temp;
            temp = search(root, word);
            if (temp == NULL){
                printf("-1 -1\n");
            }
            else{
                printf("%d %d\n", temp->freq, temp->depth);
            }
        }
        else{
            return 0;
        }
    }
    
    for(int j = 0; j < cases; j++){
       if (structs[j]->word != NULL)
           printf("%s %d\n", structs[j]->word, structs[j]->freq);
        
    }
    free(structs);
    
    return 0;
}

struct tree_node* insert(struct tree_node *root, struct tree_node *node, struct tree_node** structs, int i) {

    // Inserting into an empty tree.
    if (root == NULL){
        structs[i] = node;
        return node;
    }
    int cmp = strcmp(root->word, node->word);
    if (cmp == 0){
        root->freq+=1;
        return root;
    }
    
        // element should be inserted to the right.
        if (cmp>0) {
            
            // There is a right subtree to insert the node.
            if (root->right != NULL){
                root->depth+=1;
                root->right = insert(root->right, node, structs, i);
            }
            else{
                // Place the node directly to the right of root.
                root->right = node;
            }
        }

        // element should be inserted to the left.
        else {
            
            // There is a left subtree to insert the node.
            if (root->left != NULL){
                root->depth+=1;
                root->left = insert(root->left, node, structs, i);
            }
            else{
                root->left = node;
            }
        }

        // Return the root pointer of the updated tree.
        structs[i] = node;
        return root;
    
}

// Returns a pointer to a single node storing val.
struct tree_node* create_node(int query, char newWord[20]) {

    // Allocate space for the node, set the fields.
    struct tree_node* temp;
    temp = (struct tree_node*)malloc(sizeof(struct tree_node));
    strcpy(temp->word, newWord);
    temp->query = query;
    temp->left = NULL;
    temp->right = NULL;
    temp->freq = 1;
    temp->depth = 0;

    return temp; // Return a pointer to the created node.
}

struct tree_node* search(struct tree_node* root, char *data) {
    
    struct tree_node* trav = root;
    int depth = 0;
    
    while (trav != NULL) {
        // Compare data
        int val = strcmp(trav->word, data);

        if (val == 0) {
            trav->depth = depth;
            return trav;
        }

        // Left
        else if (val < 0) {
            depth++;
            trav = trav->left;
        }

    // Right
        else {
            depth++;
            trav = trav->right;
        }
    }

  return NULL;
}
