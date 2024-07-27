/*
1. Define the structure with car name, year, and price
2. Call the structure, name it 'dreamCar'
3. Assign the attributes manually
4. printf all three attributes in one line

*/

#include <stdio.h>
#include <string.h>

// Define the structure
struct car {
    char name[256];
    int year;
    float price;
};

int main() {
    struct car dreamCar;

    strcpy(dreamCar.name, "Ford Mustang Cobra");
    dreamCar.year = 2004;
    dreamCar.price = 40000;

    // Print student info
    printf("My dream car is %s, the year is %d, and the price is around %.2lf.\n", dreamCar.name, dreamCar.year, dreamCar.price);

    return 0;
}