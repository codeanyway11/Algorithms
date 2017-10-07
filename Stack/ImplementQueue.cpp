void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    int x;
    if(s1.empty() && s2.empty()){
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        x = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    return x;
}

//Method 2

void StackQueue :: push(int x)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x); // pushes element in stack1

    while (!s2.empty()) // transfers all elements back to stack1
    {
        s1.push(s2.top());
        s2.pop();
    }
}
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if (!s1.empty()){
        int item = s1.top();

        s1.pop();
        return item;
    }
    else return -1;

}
