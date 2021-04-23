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
    /*else if (self != NULL)
    {
        printf("binary tree not null\n");
        int result;

        result = strcmp(courseName, self->course->name);
        printf("\n %d", result);

    }*/
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


void insertCourse(CourseBST *self, String courseName)
{
    self->root = insertBSTNode(self->root, courseName);
}


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
				free(to_free);
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

CourseBST newCourse()
{
	CourseBST temp;
	temp.root = NULL;
	return temp;
}


void enrollStudent(BSTNodePtr self, String courseName, int studentID)
{
    //find the bst node

    if ((strcmp(courseName, self->course->name) == 0))
    {
        // found the course at the fisrt node

        // insert student id into that node linkedlist

        /* it works here

        ListNodePtr new_student_node = malloc(sizeof(*new_student_node));
        new_student_node->id = studentID;
        new_student_node->nextNode = self->course->student->head;
        self->course->student->head = new_student_node;
        to here*/

        //insert into linkedlist in order
        ListNodePtr new_student_node = malloc(sizeof *new_student_node);
        ListNodePtr current = self->course->student->head;
        ListNodePtr prev = NULL;
        new_student_node->id = studentID;
        new_student_node->nextNode = NULL;


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

    }else if (strcmp(courseName, self->course->name) > 0) 
    {
	 enrollStudent(self->left, courseName, studentID);
	}
	else 
    {
	 enrollStudent(self->right, courseName, studentID);
	}
    

}

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

        ListNodePtr current = self->course->student->head;
        ListNodePtr prev = NULL;

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


void unenrollNewStudent(CourseBST *self, String courseName, int id)
{
    unenrollStudent(self->root, courseName, id);
}
