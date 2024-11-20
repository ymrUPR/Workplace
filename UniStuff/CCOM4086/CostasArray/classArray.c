#include <stdio.h>
#include <stdbool.h>

int main(){
    size_t arr[4] = {1, 2, 4, 3};
    size_t ans[3][3];
    bool costas[4 * 4] = {false};
    bool check = true;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i < j){
                ans[i][j] = arr[j] - arr[i];
            }
            else if(i == j){
                ans[i][j] = 0;
            }
            else{
                ans[i][j] = 0;
            }
        } 

    }
    
    printf("Triangular Difference: \n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            (i < j) ? printf("%d ", ans[i][j]) : printf("  ");
        }
        printf("\n");

      }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int diff = arr[j] - arr[i];
            if (diff <= 0 || diff >= 4*4 || costas[diff]){
                check = false;
        }
        costas[diff] = true;
      }
    }
    (check) ? printf("This array is a Costas array \n") : printf("This array isn't Costas\n");
  }
