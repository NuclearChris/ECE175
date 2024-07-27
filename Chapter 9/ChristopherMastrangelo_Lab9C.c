/*Pdeudo Code

1. Define the structure
2. Declare the fuction
3. Open the file, fscanf values into the structure 'objects'
4. close the file
5. call the function
6. Define function
    a. all customers must be above 21 (if age>21)
    b. if in california, use CA conditions for salary
        i) if married
        ii) if singe
    c. if not in california, use other conditions
        i) if married
        ii) if single

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Define the structure
struct person {
    char firstName[50];
    char lastName[50];
    int age;
    float income;
    char married;
    char state[3];
};

void findBestCustomers(struct person customers[], int count);

int main() {
    FILE *file;
    struct person customers[MAX_CUSTOMERS];
    int count = 0;

    // Open the file, return error if it doesn't open
    file = fopen("Lab9C.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file Lab9C.txt\n");
    }

    // Read the file line by line & store to customer 'objects'
    while (fscanf(file, "%s %s %d %f %c %2s",
                  customers[count].firstName,
                  customers[count].lastName,
                  &customers[count].age,
                  &customers[count].income,
                  &customers[count].married,
                  customers[count].state) == 6 && count < MAX_CUSTOMERS) {
        count++;
    }

    // Close the file
    fclose(file);

    // Find and print the best customers using function defined below
    findBestCustomers(customers, count);

    return 0;
}

void findBestCustomers(struct person customers[], int count) {
    for (int i = 0; i < count; i++) {
        //Customers must be above 21 yrs old
        if (customers[i].age > 21) {
            //For the cases in california
            if (strcmp(customers[i].state, "CA") == 0) {
                //if married & income above 150k, or not married but income above 80k
                if ((customers[i].married == 'Y' && customers[i].income >= 150000) ||
                    (customers[i].married == 'N' && customers[i].income >= 80000)) {
                    //they qualify as a 'best customer'
                    printf("Reach out to %s %s from %s, Age %d\n",
                           customers[i].firstName, customers[i].lastName, customers[i].state, customers[i].age);
                }
            } else {
                //for cases outside of california
                //if married income 100k+ or single income 60k+
                if ((customers[i].married == 'Y' && customers[i].income >= 100000) ||
                    (customers[i].married == 'N' && customers[i].income >= 60000)) {
                    //they qualify as 'best customer'
                    printf("Reach out to %s %s from %s, Age %d\n",
                           customers[i].firstName, customers[i].lastName, customers[i].state, customers[i].age);
                }
            }
        }
    }
}