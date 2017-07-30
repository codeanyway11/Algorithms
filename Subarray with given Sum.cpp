//Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number..

//Method 1 (BruteForce)
int subArraySum(int arr[], int n, int sum){
    int curr_sum, i, j;
    for(i=0; i<n; i++){
        curr_sum = arr[i];
        for(j=i+1; j<=n; j++){
            if(curr_sum == sum){
                printf("Sum found between indexes %d & %d\n", i, j-1);
                return 1;
            }
            if(curr_sum >sum || j==n)
            break;
            curr_sum+= arr[j];
        }
    }
    printf("No such subarray found");
    return 0;
}

//Method 2 (Efficient)
//Start by considering element at 1st first position. Traverse and keep adding. If curr_sum ==sum print. If it exceeds, delete the trailing elements
int subArraySum(int arr[], int n, int sum){
    int curr_sum= arr[0], start =0, i;
    for(i =1; i<n; i++){
        while(curr_sum > sum && start < i-1){
            curr_sum-= arr[start];
            start++;
        }
        if(curr_sum == sum)
        {
            printf("Sum found between indexes %d & %d", start, i-1);
            return 1;
        }
        if(i<n)
        curr_sum +=arr[i];
    }
    printf("No Subarray Found\n", );
    return 0;
}

//Method 3
//Handles negative numbers
//This solution has Time Complexity O(n) & Space Complexity O(n).
//Why the above solution doesn't work for array containing negative numbers is because as soon as the curr_sum > sum, we start substracting from the beginning.
int subArraySum(int arr[], int n, int sum){
    unordered_map<int, int> map;
    int curr_sum =0;
    for(int i=0; i<n; i++){
        curr_sum+=a[i];
        if(curr_sum == sum){
            cout<<"Sum found from index 0 to "<<i<<endl;
            return;
        }
        if(map.find(curr_sum-sum)!=map.end()){
            cout<<"Sum found between indexes "map[curr_sum-sum]+1<<" to "<<i<<endl;
            return;
        }
        map[curr_sum]=i;
    }
}
