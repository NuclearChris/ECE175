/*

This program uses linear interpolation of known salinity and freezing temperature values of water
to predict freezing values of water with different salinity values that are not given in the table.
The initial interpolation is done in Fahrenheit, and then converted to Celsius in Part 3.

Pseudo Code:

Part 1
1. Declare 5 known variables and 1 unknown variable (we're solving for freezing temp of sample tSampleF)
2. Declare 2 variables - the derivative (or slope) dTds or (t1-t0)/(s1-s0) ---> also deltaS = (sSample-s0)
3. Perform linear interpolation using the equation T = t0 + slope*deltaS = t0 + dTds*deltaS (calculus)
4. Print result

Part 2
1. Format print statement significant digits by changing %lf to %.2lf and %.4lf

Part 3
1. Declare 2 new variables; tSampleC (freezing point in celsius) and sPPT (salinity in parts-per-thousand)
2. Convert celsius from fahrenheit using C = 5/9*(F-32)
3. Convert PPT from percent using sPPT = 10*sSample (sSample is in percent)
4. Print values again

*/

#include <stdio.h>
#include <math.h>

// Part One

int main () {

// This first group of doubles is the 5 given values, plus 1 unknown
    double t0 = 28.6000;
    double t1 = 21.1854;
    double s0 = 3.47;
    double s1 = 10.00;
    double sSample = 7.734;
    double tSampleF;

// dTds is the derivative of temperature with respect to salinity dT/ds (the slope)
// deltaS is the difference of salinity 
// dT/ds * ds = dT ---> tSample = t0 + dT = t0 + dTds*deltaS
// This is the same as the formula given, but uses calculus-type variables
 
    double dTds;
    double deltaS;

// dTds is essentially the slope of dT/ds (rise over run)
    dTds = (t0-t1)/(s0-s1);
// deltaS is the difference in sample salinity from s0 (the run)
    deltaS = sSample-s0;

// dT/ds * ds = temperature difference from t0
// T = t0 + deltaT

    tSampleF = t0 + dTds*deltaS;
    printf("Part One\n");
    printf("The predicted freezing temperature of water with a salinity\nof %lf percent will be %lf degrees Fahrenheit.\n\n", sSample, tSampleF);


// Part 2
    printf("Part Two\n");
    printf("The predicted freezing temperature of water with a salinity\nof %.2lf percent will be %.4lf degrees Fahrenheit.\n\n", sSample, tSampleF);

// Part 3
    double tSampleC;
    double sPPT;
//Convert to Celsius from Fahreheit using the equation C = 5*(F-32)/9
    tSampleC = 5*(tSampleF-32)/9;
//To convert from percent (parts per hundred) to parts per thousand - multiply by 10
    sPPT = 10*sSample;

    printf("Part Three\n");
    printf("The predicted freezing temperature of water with a salinity\nof %.2lf parts per thousand will be %.4lf degrees Celsius.\n\n", sPPT, tSampleC);


    return 0;
}