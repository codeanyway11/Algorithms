void QueueStack :: push(int x)
{
    // Your Code
    q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    // Your Code
    if(q1.empty())
    return -1;
    int size=q1.size();
    if (size==1)
    {
        int element=q1.front();
        q1.pop();
        return element;
    }
    while (size!=1)
    {
        int element=q1.front();
        q1.pop();
        size--;
        q2.push(element);
    }
    int element=q1.front();
    q1.pop();
    swap(q1,q2);
    return element;
}

//method 2
void QueueStack :: push(int y)
{
    if(q1.empty()){
        q1.push(y);
    }
    else{
        while(!q1.empty()){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.push(y);
        while(!q2.empty()){
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
    }

}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty())
    return -1;
    int element = q1.front();
    q1.pop();
    return element;
}
