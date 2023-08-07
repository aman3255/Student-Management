#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int rollNo;
    char contactInfo[50];
    float cgpa;
} student;

student students[MAX_STUDENTS];

int numStudents = 0;

void addStudent() {
    student newStudent;
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNo);
    printf("Enter contact information: ");
    scanf("%s", newStudent.contactInfo);
    printf("Enter CGPA: ");
    scanf("%f", &newStudent.cgpa);
    students[numStudents++] = newStudent;
    printf("Student added successfully.\n");
}

void deleteStudent() {
    int rollNo, i, j;
    printf("Enter roll number of student to be deleted: ");
    scanf("%d", &rollNo);
    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            for (j = i; j < numStudents - 1; j++) {
                students[j] = students[j+1];
            }
            numStudents--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("No student found with roll number %d.\n", rollNo);
}

void modifyStudent() {
    int rollNo, i;
    printf("Enter roll number of student to be modified: ");
    scanf("%d", &rollNo);
    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new contact information: ");
            scanf("%s", students[i].contactInfo);
            printf("Enter new CGPA: ");
            scanf("%f", &students[i].cgpa);
            printf("Student modified successfully.\n");
            return;
        }
    }
    printf("No student found with roll number %d.\n", rollNo);
}

int main() {
    int choice;
    while (1) {
        printf("\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Modify student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addStudent();
                break;
                
            case 2:
                deleteStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
