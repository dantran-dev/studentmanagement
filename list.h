
//the node contain id and the address of the next node  (a node inside Linked List)
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

StudentList newStudentList();


