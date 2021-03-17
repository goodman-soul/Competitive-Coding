// binary search work on sorted array
int binary_search(int arr[],int n,int key){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

//sorting

//selection sort->try to find the min element in reamaining
// array and swap that with corresponding element

// 5, 4 1 3 2-> find min thats 1 and swap 5 and 1
// -> 1,4,5,3,2 and again do this in 4 to 2...

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mid_index=i;
        int min_element=arr[i];
        //find the smallest element in unsorted part
        for(int j=i;j<n;j++){
            if(min_element>arr[j]){
                min_index=j;
                min_element=arr[j];
            }
        }
        //after this we can do the swap
        swap(arr[i],arr[min_index]);
    }
}

//bubble sort
//-> take the larger elements towards the end

// 5 4 3 2 1-> after one iteration 
// compare pair wise
// 4 3 2 1 5
// then run bubble sort agin on 0 to n-2..
void bubble_sort(int arr[],int n){
    for(int itr=1;itr<=n;itr++){
        //pair wise swapping in unsorted part
        for(int j=0;j<=(n-itr-1);j++){
            swap(arr[j],arr[j+1]);
        }
    }
}

//insertion sort-> game of cards
// insert the card in right position
// 5 2 3 0 1-> try to pick each card in i+1 and try to place them in right position

void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int e=arr[i];
        // place the current element in correct position
        int j=i-1;
        while(j>=0 && arr[j]>e){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=e; //place the element in required pos
    }   
}

//stl sort
// --------------------->
#include<algorithm>
// sort(arr,arr+n)-> quite efficient
//sort in decreasing order->comparator function
bool cmp(int a,int b){
    //cout->to check how many time it is called
    return a>=b;
}
sort(arr,arr+n,cmp);

//function passing as parameters
void function(int arr[],int n,(&cmp)(int a,int ]b)){
    // ....
}


//Generate all subarrays of given array
// ---------------------------------------->
// any continious part of array from index i to j
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        //all pairs of i j
        //printing elemnts of all subarray(i,j)
        for(int k=i;k<=j;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
}

//maximum subarray sum
// ---------------------------->
// brute force-> generate all subarrays and then check the 
// max sum
int max_sum=INT_MIN;
int left=0,right=0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum+=arr[k];
        }
        // max_sum=max(sum,max_sum);
        if(max_sum<sum){
            max_sum=sum;
            left=i;
            right=j;// to get the index
        }
    }
}
// worst case O(n^3) time complexity


// idea of cumulitive sums-> O(n^2)
at first all the elements are zero then place the array elements
cumSum[i]=cumSum[i-1]+arr[i]; //kind of like suffix array

sum of array (i,j)=cs[j]-cs[i] // so we dont need to calculate the sum again& again

// kadane's algorithms
int cs=arr[0],mx=arr[0];
for(int i=1;i<n;i++){
    cs=max(cs+arr[i],arr[i]);
    mx=max(cs,mx);
}
// time complexity -> O(n)


// given a sorted array find pair of elements that sum 
// to k -> two pointer approach
// ----------------------------------->
// int left=0,right=n-1;

2D Arrays->
// ---------------
// 2 dimentional-> matrix
<data type> a[rows][cols];
// storage-> as linear array first row then second row..
// a[3][4]-> by default garbage value


// problems->
-------------------
// 1. matrix wave pattern printing
// input : 1 4 7 10
     //    2 5 8 11
     //    3 6 9 12
// output: 1 2 3 6 5 4 7 8 9 12 11 10

// 2. spiral print of 2D array
// 3. Rotate Image(Leetcode) space complexity-> O(1)
// -> reverse all the rows and then transpose

// 4. search in row and col wise sorted array(stair case search)

// 2D character array-> each node contains a string
