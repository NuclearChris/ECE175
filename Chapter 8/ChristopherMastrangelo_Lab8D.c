#include <stdio.h>


int arrayFunction (int array[]) {
    printf("Element Two: %d \nElement Three %d\n", array[1], array[2]);
}

int main() {

    int ageArray[4] = {2, 8, 4, 12};

    arrayFunction(ageArray);

    

}