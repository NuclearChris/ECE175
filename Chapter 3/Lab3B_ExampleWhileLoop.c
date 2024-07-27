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


    time0 = 30;
    timeFinal = 60;

    time = time0;
    while (time <= timeFinal) {
        printf("elapsed time: %d \n", time);
        time += 10;
    }





    return 0;
}