#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char  name[50];
    int   age;
    float gpa;
    bool  isFullTime;

} Student;

void printStudentData(Student student)
{
    printf("%s\n", student.name);
    printf("%d\n", student.age);
    printf("%.2f\n", student.gpa);
    printf("%s\n", (student.isFullTime) ? "Yes\n" : "No\n");
}

int main()
{
    // Normal
    Student student1 = {"Artorias", 30, 2.5, true};

    // Undefined Behavior
    Student student2;

    // Init all members with 0/NULL;
    Student student3 = {0};

    printStudentData(student1);
    printStudentData(student2);
    printStudentData(student3);

    // Change obj members
    strcpy(student3.name, "Solaire of Astora");
    student3.age        = 39;
    student3.gpa        = 3.9;
    student3.isFullTime = false;

    printStudentData(student3);

    return 0;
}
