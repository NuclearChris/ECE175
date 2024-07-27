/*
1. Define the structure with name, studentNumber, gpa
2. Call the structure, name it 'student'
3. Scanf to student.name and student.studentNumber and student.gpa
4. printf all three attributes in one line

*/

#include <stdio.h>

// Define the structure
struct Student {
    char name[256];
    int studentNumber;
    float gpa;
};

int main() {
    struct Student student;

    // Input student information

    //Scanf student name
    printf("Enter student's name: ");
    scanf("%255s", student.name);
    //scanf studentNumber
    printf("Enter student number: ");
    scanf("%d", &student.studentNumber);
    //scanf GPA
    printf("Enter GPA: ");
    scanf("%f", &student.gpa);

    // Print student info
    printf("Student Information: Name: %s, Student Number: %d, GPA: %.2f\n", student.name, student.studentNumber, student.gpa);

    return 0;
}