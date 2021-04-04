#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//
void addCourseToNode(BSTNodePtr self, String courseName)
{
}

void addCourse(CourseBST *self, String courseName)
{
}

void removeCourse(CourseBST *self)
{
}

//Summary of courses and number of students enrolled in each course

void showCourseSummary(CourseBST *self)
{
}

//Print courses that student enrolled in

//try to insert into root (1st node)

void testAddCourse(BSTNodePtr self, String courseName)
{
    //create new course to insert into BST Node
    Course newCourse;
    newCourse = malloc(sizeof *newCourse);
    newCourse->name = courseName;

    if (self == NULL)
    {
        self = malloc(sizeof *self);
        self->course = newCourse;
        //newCourse->name = courseName;
        //newCourse->student = NULL;
        self->left = self->right = NULL;
    }
}