/*
Pseudo Code:
1. Define function process_temperatures which accepts pointer *temps & size
   Temps will be 0-120, so initialize max to -1 and min to 121 to avoid garbage value results
   For each element in array, if array[i]>max then max=array[i]
                              if array[i]<min then min=array[i]
                              sum+=array[i] --> avg = sum/n
    At the end, function printf max, min, avg
2. scanf user input for array size
3. Allocate dynamic memory with malloc(size*sizeof(double))
4. while loop to fill array with random numbers while i<size
5. Call the function
6. Free dynamic memory


*/

#include <stdio.h>
#include <stdlib.h>

//Function finds min, max, avg of an array
//max -1 and min 121 are set to avoid garbage values since range is 0-120
void process_temperatures(double *temps, int size) {
    double max_temp = -1;
    double min_temp = 121;
    double sum_temp = 0;
//Print the array
    printf("The array of temperatures: ");

//If temps[i]>max then it's the new max
//If temps[i]<min then it's the new min
    for (int i = 0; i < size; i++) {
        if (temps[i] > max_temp) {
            max_temp = temps[i];
        }
        if (temps[i] < min_temp) {
            min_temp = temps[i];
        }
        sum_temp += temps[i];
        printf("%.2lf ", temps[i]);
    }
    printf("\n");
    //avg = sum/n
    double avg_temp = sum_temp / size;

    printf("The maximum temperature is %.2f fahrenheit\n", max_temp);
    printf("The minimum temperature is %.2f fahrenheit\n", min_temp);
    printf("The average temperature is %.2f fahrenheit\n", avg_temp);
}

int main() {
    int size;
//User inputs the size of array
    printf("Enter the number of elements: ");
    scanf("%d", &size);
//Exception
    if (size <= 0) {
        printf("Size must be a positive integer.\n");
        return 1;
    }
//Allocate memory
    double *temps = (double *)malloc(size * sizeof(double));
//Fill array with random values 0-120
    int i = 0;
    while (i < size) {
        double temp = rand()%120;
            temps[i] = temp;
            i++;
    }
//Call the function to find min, max, avg
    process_temperatures(temps, size);
//Free the memory
    free(temps);
    return 0;
}