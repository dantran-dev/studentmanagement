#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"





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
        printf("5. Show courses summary in ordered\n");
        printf("6. Show number of students by course\n");
        printf("7. Show coursers enrolled by a student\n");
        printf("8. Quit\n");

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
                printf("Please enter course name to enroll student:");
                scanf("%s", courseTitle);
                printf("Please enter student ID to enroll:");
                scanf("%d", &studentNo);

                enrollNewStudent(&myBST, courseTitle, studentNo);
                printf("----------------------------------------------\n");
                printf("Student %d has been added to the course %s\n", studentNo, courseTitle);
                printCourse(&myBST);
                printf("----------------------------------------------\n");
                
                break;
            case 4:
                courseTitle = malloc(sizeof *courseTitle);
                printf("Please enter course name to unenroll a student:");
                scanf("%s", courseTitle);
                printf("Please enter student ID to unenroll:");
                scanf("%d", &studentNo);

                unenrollNewStudent(&myBST, courseTitle, studentNo);
                printf("----------------------------------------------\n");
                printf("Student %d has been unenrolled from the course %s\n", studentNo, courseTitle);
                printCourse(&myBST);
                printf("----------------------------------------------\n");
                
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                free(courseTitle);
                break;
            default:
                printf("Wrong selection! Please try again \n");
            
        }

    } while (choice != 8);

    return 0;



}


