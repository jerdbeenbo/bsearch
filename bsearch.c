#include <stdio.h>

/*
    This was my first attempt at properly learning C with a binary search algorithm, it will remain unfinished as a good
    learning experience and where I experienced my first issue with C

    When passing the array data to another function, i've experienced
    array decay = the parsed value "decayed" into a pointer referencing the arrays
    first element.

*/



void main() {

    FILE *fptr;
    fptr = fopen("data.txt", "r"); // -> open the file in read mode
    //store file
    char dataString[1000];
    fgets(dataString, 1000, fptr);

    //compute file (store data in array)

    //Close the file
    fclose(fptr);



    //initialise some data

    int data[] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
    };
    // Here, sizeof(my_array) correctly gives me 40 (10 ints × 4 bytes each)

    int target = 10;


    printf("Target: %d is found at index %d\n", target, binary_search(data, target));
}
//              -> POINTER
int binary_search(int data[], int target) {

    //set initial values
    int low = 0;
    int high = sizeof(data) - 1;
    // data is actually just a pointer!
    // sizeof(data) gives you the size of a pointer (4 or 8 bytes typically)

    printf("Size of array: %d", high);

    int mid = (low + high) / 2;
    int guess = data[mid];

    while (low <= high) {
        //reasign values each iteration (each guess)
        mid = (low + high) / 2;
        guess = data[mid];

        if (guess == target) {
            return mid;
        }
        //if guessed number is higher than the target number numerically
        else if (guess > target) {
            //reassign high to mid minus itself
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    //if target doesn't exist in the array return -1;
    return -1;
}