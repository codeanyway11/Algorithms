

/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    if(head1==NULL)
    return head2;
    else if(head2==NULL)
    return head1;

    struct Node* newNode=NULL;
    if(head1->data <= head2->data)
    {
        newNode = head1;
        newNode->next = SortedMerge(head1->next, head2);
    }
    else{
        newNode =head2;
        newNode->next = SortedMerge(head1, head2->next);
    }
    return newNode;
}
