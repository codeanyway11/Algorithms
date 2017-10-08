/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is
class Queue {
private:
    int arr[10001];
    int front;
    int rear;
public :
    Queue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue */
void Queue :: push(int x)
{
    // if(rear+1==front)
    // return;
    arr[rear]=x;
    rear++;
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
    if(front == rear){
        return -1;
    }
    else{
        int x= arr[front];
        front++;
        return x;
    }
}
