#include <stdio.h> //header file provides you access to input/output functions (printf scanf)
#include <math.h>

int main()
{
   
    double a = 0;
    double b = 0;
    double c;

    printf("Enter the value of a: \n");
    scanf("%lf", &a); 
    printf("Enter the value of b \n");
    scanf("%lf", &b);
    c = a*a + b*b;
    double C = sqrt(c);
    printf("The value of C is \n %lf", C);

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