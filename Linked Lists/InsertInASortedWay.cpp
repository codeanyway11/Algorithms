/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
structure of the node of the list is as
struct node
{
	int data;
	struct node* next;
};
*/
void sortedInsert(struct node** head_ref, int data)
{
    struct node* temp = *head_ref;
    struct node* newNode= new node();
    newNode->data = data;
    newNode->next = NULL;

    if(temp == NULL || temp->data>=newNode->data){
        newNode->next= temp;
        *head_ref=newNode;
        return;
    }
    else{
        while(temp && temp->next && temp->next->data < newNode->data){
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next=newNode;
        return;
    }
}
