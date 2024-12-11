#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define NEW_SIZE 10

//This function checks for duplicate elements in the given row
//By iterating through each pair of elements and comparing them
int duplicateCheck(int* row, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){ // j will always start at i+1 (given the size allows it) to be able to compare 
            if(row[i] == row[j]){
                return 1;
            }
        }
    }
    return 0;
}

int checkDTable(int* arr, int size){
    int diffTable [size - 1][size - 1];
     //Outer for loop that represents both the column of the table and the scaling step for the difference.
    for(int step = 1; step < size; step++){
        //Inner loop that helps us access the row for the table and the elements in the input array.
        for (int i = 0; i < size - step; i++){
            diffTable[step - 1][i] = arr[i + step] - arr[i];
            //printf("diffTable[%d][%d] = %d\n", step - 1, i, diffTable[step -1][i]);
      }
    }


//  This block checks if the array is a Costas array by checking if there exists a duplicate number
//  in each row of the difference table generated using the input array.
    for(int i = 0; i < size - 1; i++){
        //We will call helper function duplicateCheck to help us verify if there exists a duplicated number 
        //within the same row of our difference table, thus making it NOT a costas array.
        if(duplicateCheck(diffTable[i], size - 1 - i)){
            //printf("checkDTable second loop: duplicateCheck returned 1, I gave it size %d\n",size - 1);
            return 0;
        }
    } 
    return 1;
}

//This is the function responsible for the magic:
//The one behind the extension of a size 5 Costas array
//to a size 10 Costas array.
int arrayExtension(int inputArr[SIZE], int extendedArr[NEW_SIZE]){
    
    for(int i = 0; i < SIZE; i++){ // This loop copies the initial input array into the new extended array, so it has the same starting elements
        extendedArr[i] = inputArr[i];
    }
    //To avoid my own confusion, I named it index instead of my usual i.
    //We make a new for loop, responsible for accessing the empty elements in order
    //to flesh out our new array with the next 5 elements we are missing.
    for(int index = SIZE; index < NEW_SIZE; index++){ 
        int validNumber = 0; //Little number that will act as a boolean to indicate whether or not we've found a number that won't violate the costas property if added to the array.

      for(int scaleVal = 1; scaleVal < 1000; scaleVal++){
        extendedArr[index] = scaleVal; // Assign a possible value to the extended array to then check if it violates the costas array property.
        if(checkDTable(extendedArr, index + 1)){ //Calls checkDTable to verify Costas integrity with a new updated size for this singular addition.
            //printf("Valid Number %d found for index %d\n", scaleVal, index); //This is here for debugging purposes
            validNumber = 1; //We have found a validNumber and need not check for another number in this array element.
            break;
        }
      }

      if(!validNumber){ //If we never found a valid number for the element, then return 0
          return 0;
      }
    }

    return 1;
  }

int main(){
    int inputArr[SIZE] = {1, 3, 2, 5, 6}; //Hard coded size 5 Costas Array 
    int extendedArr[NEW_SIZE];
    if (!checkDTable(inputArr, SIZE)) { // Check if the initial array truly is a Costas Array
        printf("Input array is not a valid Costas array.\n");
        return 1;
    }

    if(arrayExtension(inputArr, extendedArr)){ // Attempt to extend the Costas Array to a size 10
        printf("Successfully extended the array to:\n");
        // Time to print the new array to the user
        printf("Costas 10: { ");
        for (int i = 0; i < NEW_SIZE; i++){
            printf("%d ", extendedArr[i]);
        }
        printf("}\n");
    }
    
    else{
        printf("Array couldn't be extended (scale size 1000)\n");
    }
  return 0;
}
