#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/*Assignment 2
**Student Name: Tran Cong Danh
**Student ID: 491554
*/

BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

BSTNodePtr insertBSTNode(BSTNodePtr self, String courseName)
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
    
    else if (strcmp(self->course->name, newCourse->name) > 0)
    {
        self->right = insertBSTNode(self->right, courseName);
    }
        
    else if(strcmp(self->course->name, newCourse->name) < 0)
    {
        self->left = insertBSTNode(self->left, courseName);
      
    }
    return self;
}

//this method is use for 1st function
// insert a course into BST

void insertCourse(CourseBST *self, String courseName)
{
    self->root = insertBSTNode(self->root, courseName);
}

//delete a node from BST 

BSTNodePtr deleteCourseNode(BSTNodePtr self, String courseName)
{
    if (self != NULL) {
		if (strcmp(self->course->name, courseName) == 0) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->course->name = successor->course->name;
				self->right = deleteCourseNode(self->right, self->course->name);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free); // empty allocated memory
			}
		}
		else if (strcmp(courseName, self->course->name) > 0) {
			self->left = deleteCourseNode(self->left, courseName);
		}
		else {
			self->right = deleteCourseNode(self->right, courseName);
		}
	}
	return self;
}

// This method is use for 2nd function
// Delete a course from BST
void deleteCourse(CourseBST* self, String courseName) {
	self->root = deleteCourseNode(self->root, courseName);
}

void print_pre_order_bst_node(BSTNodePtr self) 
{

    ListNodePtr current_for_print;
    current_for_print = malloc(sizeof *current_for_print);
    
	if (self != NULL) {
	
		printf("%s ", self->course->name);

        current_for_print = self->course->student->head;
        while (current_for_print != NULL)
        {
            
            printf("- %ld -", current_for_print->id);
            current_for_print = current_for_print->nextNode;
        }
        printf("\n");
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
		
	}
	
}

void printCourse(CourseBST* self) {
	print_pre_order_bst_node(self->root);
}

//define a new course
CourseBST newCourse()
{
	CourseBST temp;
	temp.root = NULL;
	return temp;
}

// Insert (enroll) a student into a node inside linkedlist
void enrollStudent(BSTNodePtr self, String courseName, int studentID)
{
    //find the bst node

    if ((strcmp(courseName, self->course->name) == 0))
    {
        // found the course at the fisrt node

        // insert student id into that node linkedlist


       
        ListNodePtr new_student_node = malloc(sizeof *new_student_node); // allocate memory for new node
        ListNodePtr current = self->course->student->head; // connect the current node to the head 
        ListNodePtr prev = NULL;
        new_student_node->id = studentID;
        new_student_node->nextNode = NULL;

         //insert into linkedlist in order

        while (current != NULL && current->id < studentID) {
        prev = current;
        current = current->nextNode;
        }

        if (current == self->course->student->head) { // at front
        new_student_node->nextNode = current;
        self->course->student->head = new_student_node;
        } 
        else {                     // middle
        new_student_node->nextNode = current;
        prev->nextNode = new_student_node;
        }

    }else if (strcmp(courseName, self->course->name) > 0) // if the course name smaller than the entered course name
    {
	 enrollStudent(self->left, courseName, studentID); //recursive to the left tree
	}
	else 
    {
	 enrollStudent(self->right, courseName, studentID); //recursive to the right tree
	}
    

}
//this function is use for 3th function
// enroll a student to existed course
void enrollNewStudent(CourseBST *self, String courseName, int id)
{
    enrollStudent(self->root, courseName, id);
}


void unenrollStudent(BSTNodePtr self, String courseName, int studentID)
{
    //find the bst node

    if ((strcmp(courseName, self->course->name) == 0))
    {
        // found the course at the fisrt node

        // insert student id into that node linkedlist

        ListNodePtr current = self->course->student->head; // initialise current node link to the head
        ListNodePtr prev = NULL;
        //use while loop to print out the move and link the nodes
        while (current!= NULL)
        {
            if (current->id == studentID)
            {
                if(prev == NULL)
                {
                    self->course->student->head = current->nextNode;
                    free(current);
                    current = self->course->student->head;
                }else
                {
                    prev->nextNode = current->nextNode;
                    free(current);
                    current = prev->nextNode;
                }
            }
            else
            {
                prev = current;
                current = current->nextNode;
            }
        }
      
    }
}

//this method is use for function 4th
//unenroll a student from the linked list (remove)
void unenrollNewStudent(CourseBST *self, String courseName, int id)
{
    unenrollStudent(self->root, courseName, id);
}



void print_inorder_bst_node(BSTNodePtr self) 
{
    int counter = 0;

    ListNodePtr current_for_print;
    current_for_print = malloc(sizeof *current_for_print);
    
	if (self == NULL) {
	
		return;
	}

    print_inorder_bst_node(self->left);
    current_for_print = self->course->student->head;

    while (current_for_print != NULL)
        {
            counter = counter + 1;
        
            current_for_print = current_for_print->nextNode;
        }
    printf("%s has %d students \n", self->course->name, counter);
    print_inorder_bst_node(self->right);

	
}
//this method is use for function 5th
// print course summary in order
void printInOrderCourse(CourseBST* self) {
	print_inorder_bst_node(self->root);
}