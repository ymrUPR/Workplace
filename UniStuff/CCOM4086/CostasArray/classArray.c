#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Helper function whose task is to verify each row of our difference table for repeated numbers.
int duplicateCheck(int* row, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(row[i] == row[j]){
                return 1;
            }
        }
    }
    return 0;
}

// Helper function whose task is to print out the difference table to the user.
int printDTable(int diffTable[SIZE - 1][SIZE - 1]){
    //Nested for loops that are used to access the rows and columns of the difference table. 
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - 1 - i; j++){
            printf("%d ", diffTable[i][j]); // Prints out the columns of each row to the CLI.
        }
        printf(";\n"); // A little indicator of the end of a row
    }
}


int main(){
    int inputArr[SIZE] = {1, 3, 2, 5, 6, 1, 1, 6, 10, 3}; // Hard coded input array
    int diffTable[SIZE - 1][SIZE - 1]; // Defining a difference table we will use.
    int isCostas = 1; // Fake boolean to know if our array ends up being Costas

    //Outer for loop that represents both the column of the table and the scaling step for the difference.
    for(int step = 1; step < SIZE; step++){
        //Inner loop that helps us access the row for the table and the elements in the input array.
        for (int i = 0; i < SIZE - step; i++){
            diffTable[step - 1][i] = inputArr[i + step] - inputArr[i];
      }
    }

 
  //PRINT BLOCK (Commented out for assembly purposes)
   //Prints out the original array for user to see:
    printf("Original array = {"); 
    for(int i = 0; i < SIZE; i++){
        printf("%d ", inputArr[i]);
    }
    printf("}\n");
    
    //Prints out the generated difference table in accordance to input array:
    printf("Difference Table\nT = {\n");
    printDTable(diffTable); //Calls helper function printDTable to access and print the difference table
    printf("}\n");

//  This block checks if the array is a Costas array by checking if there exists a duplicate number
//  in each row of the difference table generated using the input array.
    for(int i = 0; i < SIZE - 1; i++){
        //We will call helper function duplicateCheck to help us verify if there exists a duplicated number 
        //within the same row of our difference table, thus making it NOT a costas array.
        if(duplicateCheck(diffTable[i], SIZE - 1 - i)){
            isCostas = 0;
            break;
        }
    }
//  Depending on our results of our duplicateCheck function, using 0 for false and 1 for true, we will know
//  if our array was a Costas array or not, and we will give the user a print in accordance to our findings.
    (isCostas) ? printf("The array is a Costas array.\n") : printf("The array is NOT a Costas array.\n");

//  Job done!
    return 0;
}
