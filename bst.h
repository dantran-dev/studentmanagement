
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


typedef char *String;

//Course has course name and the list of students (a node inside BST)
typedef struct course
{
    String name;
    StudentList student;
} * Course;

//BST node has course (course name + student linked list)  and address to left and right (course)
typedef struct bstNode
{
    Course course;
    struct bstNode *left;
    struct bstNode *right;
} * BSTNodePtr;

//root of the BST (Course Structure)

typedef struct bst
{
    BSTNodePtr root;
} CourseBST;


CourseBST newCourse();


void insertCourse(CourseBST *self, String courseName);

void printCourse(CourseBST* self);

void deleteCourse(CourseBST* self, String courseName);

void enrollNewStudent(CourseBST *self, String courseName, int id);

void unenrollNewStudent(CourseBST *self, String courseName, int id);

//void enrollNewStudent(CourseBST *self, String courseName, int id);