//
//  main.c
//  countingStars
//
//  Created by Andrew Van Siclen on 9/20/21.
//

#include <stdio.h>

#define MAXCASES 50
#define MAX 50
#define NUM_MOVES 4

const int DX[] = {-1,0,0,1};
const int DY[] = {0,-1,1,0};

int solve(char map[][MAX+1], int rows, int cols);
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill);


int main() {
    
    for (int i = 1; i < MAXCASES; i++){
        
        char map[MAX][MAX+1];
        
        int rows, cols;
        scanf("%d %d", &rows, &cols);
        if (rows > 100 || cols > 100 || rows < 0 || cols < 0){
            return 0;
        }
        
        for (int j = 0; j < rows; j++){
            scanf("%s", map[i]);
        }
        
        int stars = solve(map, rows, cols);
        
        if (stars == 1){
            printf("Case %d: 1\n", i);
        }
        else{
            printf("Case %d: %d\n", i, stars);
        }
    }
    
    return 0;
}

int solve(char map[][MAX+1], int rows, int cols){
    
    int i, j, numstars = 0;
    
    for(i = 0; i < rows; i++){
        
        for (j = 0; j < cols; j++){
            
            if(map[i][j] == '-'){
                numstars++;
                floodfill(map, rows, cols, i, j, '-', '#');
            }
            
        }
    }
    
    return numstars;
    
    
}
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill){
    
    if(x < 0 || x >= rows || y < 0 || y >= cols){
        return;
    }
    
    if(map[x][y] != oldfill){
        return;
    }
    
    map[x][y] = newfill;
    
    for(int i = 0; i < NUM_MOVES; i++){
        floodfill(map, rows, cols, x+DX[i], y+DY[i], oldfill, newfill);
    }
    
}
