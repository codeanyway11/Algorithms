/* Link list Node
struct Node {
int data;
Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if(!head){
        return -1;
    }
    struct Node* slow= head;
    struct Node* fast = head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;

}

//Other Method
int getMiddle(Node *head)
{
    if(!head)
    return -1;
    struct Node* mid=head;
    int count = 0;
    while(head){
        //update mid when count is an odd number
        if(count & 1){
            mid= mid->next;
        }
        count++;
        head=head->next;
    }
    return mid->data;
}
