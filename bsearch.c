#include <stdio.h>
void main() {

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
        10
    };

    int target = 4;


    printf("Target: %d is found at index %d\n", target, binary_search(data, target));
}

int binary_search(int data[], int target) {

    int low = 0;
    int high = sizeof(data) - 1;

    int mid = (low + high) / 2;
    int guess = data[mid];

    while (low <= high) {
        mid = (low + high) / 2;
        guess = data[mid];

        if (guess == target) {
            return mid;
        }
        else if (guess > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    //if it isn't found, return -1
    return -1;
}