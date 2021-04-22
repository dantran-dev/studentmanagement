#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include "list.h"

int main()
{

    int choice;

    do
    {
        printf("______Student Database Management_________\n");
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

    } while (choice == 8);
}