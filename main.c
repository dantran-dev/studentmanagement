#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

/*Assignment 2
**Student Name: Tran Cong Danh
**Student ID: 491554
*/



int main()
{

    int choice, studentNo;
    char *courseTitle;
    
    
    CourseBST myBST = newCourse();

    do
    {
        printf("\n");
        printf("STUDENT MANAGEMENT\n");
        printf("\n");
        printf("1. Add a course\n");
        printf("2. Remove a course\n");
        printf("3. Enroll a student\n");
        printf("4. Un-enroll a student\n");
        printf("5. Show total student of courser in order\n");
        printf("6. Show ordered list of students\n");
        printf("7. Show courses enrolled by a student\n");
        printf("0. Quit\n");

        printf("Please select an option:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                
                courseTitle = malloc(sizeof *courseTitle);
                printf("Please enter course name to added:");
                scanf("%s", courseTitle);
                insertCourse(&myBST, courseTitle);
                printf("---------------------------------------------\n");
                printf("New course has been added:\n");
                printCourse(&myBST);
                printf("---------------------------------------------\n");
                
                
                break;
            case 2:
                courseTitle = malloc(sizeof *courseTitle);
                printf("Please enter course name to remove:");
                scanf("%s", courseTitle);
                deleteCourse(&myBST, courseTitle);
                printf("----------------------------------------------\n");
                printf("The %s course has been removed:\n", courseTitle);
                printCourse(&myBST);
                printf("----------------------------------------------\n");
                
                break;
            case 3:
                courseTitle = malloc(sizeof *courseTitle);
                printf("Please enter student ID to enroll:");
                scanf("%d", &studentNo);
                printf("Please enter course name to enroll student:");
                scanf("%s", courseTitle);
                

                enrollNewStudent(&myBST, courseTitle, studentNo);
                printf("----------------------------------------------\n");
                printf("Student %d has been added to the course %s\n", studentNo, courseTitle);
                printCourse(&myBST);
                printf("----------------------------------------------\n");
                
                break;
            case 4:
                printf("Please enter student ID to unenroll:");
                scanf("%d", &studentNo);
                courseTitle = malloc(sizeof *courseTitle);
                printf("Please enter course name to unenroll a student:");
                scanf("%s", courseTitle);
                

                unenrollNewStudent(&myBST, courseTitle, studentNo);
                printf("----------------------------------------------\n");
                printf("Student %d has been unenrolled from the course %s\n", studentNo, courseTitle);
                printCourse(&myBST);
                printf("----------------------------------------------\n");
                
                break;
            case 5:
                printf("----------------------------------------------\n");
                printf("Course summary in order\n");
                printInOrderCourse(&myBST);
                printf("----------------------------------------------\n");

                
                break;
            case 6:
                printf("---------------------------------------------------\n");
                printf("Course summarry with ordered Student ID\n");
                printCourse(&myBST);
                printf("---------------------------------------------------\n");
                break;
            case 7:
                break;
            case 0:
                printf("GoodBye!\n");
                free(courseTitle);
                
                break;
            default:
                printf("Wrong selection! Please try again \n");
            
        }

    } while (choice != 0);

    return 0;



}


