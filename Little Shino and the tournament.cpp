#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin>>n>>q;
    int strength[n];
    int pos[n];
    int temp;
    for(int  i=0; i<n; i++)
    {
        scanf("%d", &temp);
        strength[i] = temp;
    }
    for(int  i=0; i<=n-1; i++)
    {
        pos[i]=0;
    }

    while(true){
    	int remains=0;
    	int a, b, i, j;
    	for( i=0; i<n; i++){
    		if(strength[i]){
    			a=i;
    			remains+=1;
    		//	printf("Value of a is %d\n",a);
    			for( j=i+1; j<n; j++){
    				if(strength[j]){
    					b=j;
    					remains+=1;
    				//	printf("Value of b is %d\n",b);
    					break;
    				}
    			}
    			if(j==n){
    				break;
    			}
    			else{
    				if(strength[a] > strength[b])
    					strength[b]=0;
    				else
    					strength[a]=0;
    				pos[a]+=1;
    				pos[b]+=1;
    				i=b;
    			}
    		}
    	}
    	if(remains == 1){

    		break;
    		}
    }
     for(int t = 0; t < q; t++){
        int p;
        scanf("%d", &p);
        printf("%d\n", pos[p - 1]);
    }

    return 0;
}
