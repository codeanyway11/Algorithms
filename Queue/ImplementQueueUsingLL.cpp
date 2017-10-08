/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the node of the queue is
struct QueueNode
{
    int data;
    QueueNode *next;
};
and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue*/
void Queue:: push(int x)
{
       struct QueueNode* newNode = new QueueNode();
       newNode->data= x;
       newNode->next= NULL;
       if(rear == NULL){
           front = newNode;
           rear = newNode;
       }
       else{
           rear->next =newNode;
           rear = newNode;
       }
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
       if(front==NULL)
        return -1;
        else{
            struct QueueNode* temp= front;
            int x= temp->data;
            front=temp->next;
            free(temp);
            if(!front){
                rear=NULL;
            }
            return x;
        }
}
