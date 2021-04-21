#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

} *StudentList;

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
} *BSTNodePtr;

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

    StudentList newStudentList;
    newStudentList = malloc(sizeof *newStudentList);

    newStudentList->head = NULL;

    //courseName = (char*)malloc(sizeof *courseName);

   
    newCourse->name = courseName;
    newCourse->student = newStudentList;

    if (self == NULL)
    {
        self = malloc(sizeof *self);
        self->course = newCourse;
        self->left = self->right = NULL;
    }
    /*else if (self != NULL)
    {
        printf("binary tree not null\n");
        int result;

        result = strcmp(courseName, self->course->name);
        printf("\n %d", result);

    }*/
    else if (strcmp(self->course->name, newCourse->name) > 0)
    {
        self->right = testInsert(self->right, courseName);
    }
        
    else if(strcmp(self->course->name, newCourse->name) < 0)
    {
        self->left = testInsert(self->left, courseName);
      
    }
    return self;
}


void insertCourse(CourseBST *self, String courseName)
{
    self->root = testInsert(self->root, courseName);
}


void print_pre_order_bst_node(BSTNodePtr self) {
	if (self != NULL) {
	
		printf("%s\n", self->course->name);
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
		
	}
	
}
void print_pre_order_bst(CourseBST* self) {
	print_pre_order_bst_node(self->root);
}

BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

BSTNodePtr deleteCourse(BSTNodePtr self, String courseName)
{
    if (self != NULL) {
		if (strcmp(self->course->name, courseName) == 0) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->course->name = successor->course->name;
				self->right = deleteCourse(self->right, self->course->name);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (strcmp(courseName, self->course->name) > 0) {
			self->left = deleteCourse(self->left, courseName);
		}
		else {
			self->right = deleteCourse(self->right, courseName);
		}
	}
	return self;
}


void delete_bst(CourseBST* self, String courseName) {
	self->root = deleteCourse(self->root, courseName);
}


void enrollStudent(BSTNodePtr self, String courseName, int studentID)
{   

    //find the courseName where the student will be enrolled into
    //if found at the first node, insert student into that node
    if(self == NULL || (strcmp(courseName, self->course->name) == 0))
    {
        
        //insert into linkedlist by in order

        //self->course->student->head->id = studentID;

        
    }
    else if (strcmp(self->course->name, courseName) > 0)
    {
        enrollStudent(self->left, courseName, studentID);
    }
    else 
    {
        enrollStudent(self->right, courseName, studentID);
    }

}

CourseBST newCourse()
{
	CourseBST temp;
	temp.root = NULL;
	return temp;
}
int main()
{

    CourseBST myBST = newCourse();


    insertCourse(&myBST, "IT");
    insertCourse(&myBST, "Nurse");
    insertCourse(&myBST, "BUSINESS");
    insertCourse(&myBST, "ART");

    print_pre_order_bst(&myBST);

    printf("after deteled a course\n");
    delete_bst(&myBST, "IT");

    print_pre_order_bst(&myBST);
}

//test insert BSTNode
