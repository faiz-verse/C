#include <stdio.h>
#include <math.h> // for using sqrt()
#include <string.h>
#include <stdlib.h>

// Defining the struct so that i can be passed into the function outside the main
struct coordinates
{
    int x;
    int y;
};

float calculateDistance(struct coordinates c1, struct coordinates c2)
{
    float dx = c2.x - c1.x;
    float dy = c2.y - c1.y;
    float distanceSquared = dx * dx + dy * dy;
    return distanceSquared;
}

int main()
{
    // Defining the structure
    struct Point1
    {
        int x;
        int y;
    };
    // creating variable of type stuct
    struct Point1 p1;
    p1.x = 5;
    p1.y = 10;
    printf("Point 1 is x: %d, y: %d\n\n", p1.x, p1.y);

    // Another way of using stuctures,
    // using typedef to avoid using the whole name to create or pass stuct vairiable using - struct Points p1
    typedef struct
    {
        int x;
        int y;
    } Point2;

    Point2 p2;
    p2.x = 10;
    p2.y = 15;
    printf("Point 2 is x: %d, y: %d\n\n", p2.x, p2.y);

    /*
    🔹 Task 1: Define and use a struct
        Create a struct Point with x and y coordinates.
    */
    struct coordinates c1; // point 1
    c1.x = 10;
    c1.y = 10;
    struct coordinates c2; // point 2
    c2.x = 20;
    c2.y = 20;
    float distance = sqrt(calculateDistance(c1, c2));
    printf("Distance between %d, %d and %d, %d is %.2f\n\n", c1.x, c1.y, c2.x, c2.y, distance);

    /*
    🔹 Task 2: Array of structs
    Define a struct Student with:
        int roll_no
        char * name
        int marks
    Make an array of 3 students, assign values, and print them all.
    */
    struct Student
    {
        int roll_no;
        // char *name;
        char name[50];
        int marks;
    };
    struct Student students[3];
    printf("Students are as follows: \n");
    for (int i = 0; i < 3; i++)
    {
        students[i].roll_no = i + 1;
        // if we want to use char *name
        // students[i].name = (char *)malloc(50 * sizeof(char));
        // snprintf(students[i].name, 50, "%s number %d", "Student", i + 1);
        snprintf(students[i].name, 50, "%s number %d", "Student", i + 1);
        students[i].marks = 75 + i * 2;
        printf("Roll no: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n\n", students[i].marks);
    }

    /*
    🔹 Task 4: Nested structs
        Define a struct Date with:
            int day
            int month
            int year
        Define a struct Employee with:
            int id
            char name[50]
            struct Date joining_date
        In main(), create 2 employees with their joining dates and print all details.
    */
    struct Date
    {
        int day;
        int month;
        int year;
    };
    struct Employee
    {
        int id;
        char name[50];
        struct Date joining_date;
    };
    struct Employee emp[3];
    printf("Employees are as follows: \n");
    for (int i = 0; i < 3; i++)
    {
        emp[i].id = i + 1;
        snprintf(emp[i].name, 50, "%s number %d", "Employee", i + 1);
        // using rand() => math.rand() with formula to rand in range,
        // rand() % (max - min + 1) + min
        emp[i].joining_date.day = (rand() % (31 - 1 + 1) + 1);
        emp[i].joining_date.month = (rand() % (12 - 1 + 1) + 1);
        emp[i].joining_date.year = (rand() % (2025 - 2000 + 1) + 2000);
        // printing data
        printf("Employee id: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Joining date: %d/%d/%d\n\n", emp[i].joining_date.day, emp[i].joining_date.month, emp[i].joining_date.year);
    }
}