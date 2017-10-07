/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
{
int data;
Node* next;
}; */
/* Should return data of n'th node from the end of linked list */
int getNthFromLast(Node *head, int n)
{
    struct Node* ref= head;
    struct Node* main = head;
    int count =0;
    bool flag =0;
    while(ref && count <n){
        count++;
        ref= ref->next;
    }
    while(ref){
        ref= ref->next;
        main=main->next;
    }

    return main->data;

}
