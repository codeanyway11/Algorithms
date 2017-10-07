#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void swapnodes(struct node** head, int x, int y){
    if(x==y)
    return;

    struct node* prevX= NULL;
    struct node* prevY=NULL;
    struct node* currX= *head;
    struct node* currY= *head;

    while(currX && currX->data!=x){
        prevX= currX;
        currX= currX->next;
    }

    while(currY && currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }

    if(currX==NULL || currY==NULL)
    return;

    if(prevX==NULL){
        *head = currY;
    }
    else{
        prevX->next =currY;
    }

    if(prevY==NULL){
        *head = currX;
    }
    else{
        prevY->next = currX;
    }

    struct node* next_next =currX->next;
    currX->next = currY->next;
    currY->next = next_next;
    return;
}
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
    (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Druver program to test above function */
int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
    1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling swapnodes() ");
    printList(start);

    swapnodes(&start, 1, 7);

    printf("\n Linked list after calling swapnodes() ");
    printList(start);

    return 0;
}
