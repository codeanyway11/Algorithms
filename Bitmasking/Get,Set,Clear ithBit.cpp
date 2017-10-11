int getIthBit(int n,int i){
    return (n & (1<<i))!=0?1:0;
}

//Change ith bit of no to 1
void setIthBit(int &n,int i){
    int mask = 1<<i;
    n = (n|mask);

}
//Clear the ith bit of no to 0
void clearBit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask;
}
