Node* reverse(Node *head)
{
 if(head ==NULL || head->next==NULL)
 return head;

 struct Node* revHead = reverse(head->next);
 head->next->next = head;
 head->next = NULL;
 return revHead;
}


Node* reverse(Node* head){
    struct Node* prev= NULL;
    struct Node* curr= head;
    while(curr){
        struct Node* next_next= curr->next;
        curr->next= prev;
        prev= curr;
        curr= next_next;
    }
    return prev;
}
