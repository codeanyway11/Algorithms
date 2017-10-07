//Geeks Link: http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
void SpecialStack::push(int x)
{
    if(isEmpty()==true)
    {
        Stack::push(x);
        min.push(x);
    }
    else
    {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if( x <= y ){
            min.push(x);
        }
    }
}

int SpecialStack::pop()
{
    int x = Stack::pop();
    int y = min.pop();

    if ( y != x )
    min.push(y);

    return x;
}
