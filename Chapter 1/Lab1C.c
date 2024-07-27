#include <stdio.h> //header file provides you access to input/output functions (printf scanf)
#include <math.h>

int main()
{
   
    double x = 0;
    double y = 0;
    double z = 0;
    double H;
    double h;
    double A;

    printf("Enter the value of x: \n");
    scanf("%lf", &x); 
    printf("Enter the value of y: \n");
    scanf("%lf", &y);
    printf("Enter the value of z: \n");
    scanf("%lf", &z);
    H = sqrt(pow(y,2) - pow(x,2));
    h = sqrt(pow(z,2) - pow(x,2));
    A = x*(h+H);

    printf("H is \n %lf \n", H);
    printf("h is \n %lf \n", h);
    printf("A is: %lf", A);

    return 0;
}

// bugs ->  is an unexpected problem with software or hardware
// debugger -> A debugger is a software tool used by developers to test and debug programs during the development process.

// Source code -> compiler -> Assembler -> Object code -> Linker -> Executable file -> Loader
// Compiler -> A compiler is a software tool that translates source code written in a high-level programming language
//             into machine code or executable code that can be understood and executed by a computer.
// Assembler -> A Software that converts an assembly language code to machine code
// Object Code -> generally refers to the output, a compiled file, which is produced when the Source Code is compiled with a C compiler
// linker   -> Linker is a program in a system which helps to link object modules of a program into a single object file.
// Executable file -> Output file produced by the linker
// Loader ->  It is special program that takes input of executable files from linker, loads it to main memory, and prepares this code for execution by computer.