#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "list.h"

//Insert new student in front of the list
void addStudentInFront(StudentList *self, long data)
{
    ListNodePtr new_node = malloc(sizeof *new_node);
    new_node->id = data;
    new_node->nextNode = self->head;
    self->head = new_node;
}

//Create new Student Linked List
StudentList newStudentList()
{
    StudentList temp;
    temp.head = NULL;
    return temp;
}

//Delete student by ID

void removeStudentByID(StudentList *self, long data)
{
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    while (current != NULL)
    {
        if (current->id == data)
        {
            if (prev == NULL)
            {
                self->head = current->nextNode;
                free(current);
                current = self->head;
            }
            else
            {
                prev->nextNode = current->nextNode;
                free(current);
                current = prev->nextNode;
            }
        }
    }
}

void destroyStudentList(StudentList *self)
{
    ListNodePtr current = self->head;
    while (current != NULL)
    {
        ListNodePtr to_free = current;
        current = current->nextNode;
        free(to_free);
    }

    self->head = NULL;
}

int countStudent(StudentList *self)
{
    int count;

    ListNodePtr current = self->head;
    while (current != NULL)
    {
        count++;
        current = current->nextNode;
    }

    return count;
}
