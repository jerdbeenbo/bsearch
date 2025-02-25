#include <stdio.h>
#include <time.h>

int bsearch(int data[], int arrLength, int target) {

    //assign initial values
    int low = 0;
    int high = arrLength - 1;
    int mid = (low + high) / 2;
    int guess = data[mid];

    while (low <= high) {
        //reassign values each guess (each iteration)
        mid = (low + high) / 2;
        guess = data[mid];

        //found target
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

    //target value is not in array
    return -1;
}

void main() {
    
    int data[10] = {1, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    int target = 10;

    clock_t begin = clock();
    printf("Target %d found at index %d\n", target, bsearch(data, 10, target));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Computation time: %f\n", time_spent);
}