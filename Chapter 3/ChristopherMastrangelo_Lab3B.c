#include <stdio.h>
#include <math.h>
#include <string.h>

/*

!---PseudoCode---!

1. Scanf to select an object. 
    If 1:
        object=car
        Ts = 70F
        T_initial = 200F
        k=0.4856
        dt=10
        time0=10

    
     If 2, object=coffee..(similar to case 1) 
     If 3, object=soup... (similar to case 1)

3. While time < timeFinal
    calculate temp @ new time
    increment time by dt
    print time, temp



*/


int main() {


//Declare variables
    int Ts;
    int time;
    double Temp;
    int T_initial;
    double k;
    int dt;
    int time0;
    int timeFinal;
    int number;
    char object[256];

//Scan in number
    printf("Select an object! (enter a number):\n 1. Coffee \n 2. Soup \n 3. Car Engine \n");
    scanf("%d", &number);

    if (number == 1) {
        strcpy(object, "coffee");
        Ts = 70;
        T_initial = 200;
        k = 0.4856;
        dt = 10;
        time0 = 10;
        timeFinal = 40;
    }

    if (number == 2) {
        strcpy(object, "soup");
        Ts = 65;
        T_initial = 210;
        k = 0.05;
        dt = 10;
        time0 = 15;
        timeFinal = 45;
    }

    if (number == 3) {
        strcpy(object, "Car engine");
        Ts = 60;
        T_initial = 190;
        k = 0.0341;
        dt = 10;
        time0 = 30;
        timeFinal = 60;

    }

    printf("You've selected: %s. \n", object);

    time = time0;
    while (time <= timeFinal) {
        Temp = Ts + (T_initial - Ts)*exp(-k*time);


        printf("temp equals %.2lf at time %d \n", Temp, time);
        time += dt;
    }





    return 0;
}