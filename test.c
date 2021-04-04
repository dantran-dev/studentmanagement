#include <stdio.h>
#include <stdlib.h>

typedef char *String;

typedef struct listNode
{

    long id;
    struct listNode *nextNode;

} * ListNodePtr;

//The head of Student List (Linked List)
typedef struct list
{
    ListNodePtr head;

} StudentList;

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

BSTNodePtr testInsert(BSTNodePtr self, String courseName)
{
    //insert into first BSTNode

    Course newCourse;
    newCourse = malloc(sizeof *newCourse);

    StudentList newStudent;
    newStudent = malloc(sizeof *newStudent);

    newCourse->name = "IT";
    newCourse->student = newStudent;

    if (sell == NULL)
    {
        self = malloc(sizeof *self);
        self->course = newCourse;
        self->left = self->right = NULL;
    }
    else
    {
        self->right = testInsert(self->right, courseName);
    }
    return self;
}

void insertCourse(CourseBST *self, String courseName)
{
    self->root = testInsert(self->root, courseName);
}

CourseBST newBST()
{
    CourseBST temp;
    temp.root = NULL;
    return temp;
}

int main()
{

    CourseBST myBST = newBST();

    insertCourse(myBST, 'iT');
}

//test insert BSTNode
