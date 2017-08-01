//Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

//The following solution takes O(n) time complexity and O(n) space complexity

#include <iostream>
#include<stack>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	stack<int> stack;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];

	   int max=-10000;
	   for(int j=n-1; j>=0; j--){
	       if(a[j]>max){
	           stack.push(a[j]);
	           max=a[j];
	       }
	   }
	   while(!stack.empty()){
	       cout<<stack.top()<<" ";
	       stack.pop();
	   }
	   cout<<endl;
	}
	return 0;
}
