#include<bits/stdc++.h>
using namespace std;

// binary search-> for sorted array
//brute force ->O(n) time

int binary_search(int arr[],int n){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;//the element is not present
}

// search first and last occurance of an elment
// if mid element ==key-> note down the index-> for first element search for the left part of the array
// for last occurance-> if found the key search in the right part

int first_occurace(int arr[],int n,int key){
    int start=0,end=n-1;
    int ans=-1;
    //update in a direction that the ans values gets lower and lower
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;//explore the left part
        }else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}
int last_occurance(int arr[],int n,int key){
    int start=0,end=n-1;
    int start=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            ans=mid;
            end=mid+1; //exploring the right part
        }else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}

// binary search stl-> Rev_Day_3.cpp*

// problem 1. binary search on a rotated array
int searchRotatedArray(int arr[],int n,int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[start]<=arr[mid]){
            //two cases-> lies in left or right of the mid
            // left side is sorted and right part not
            if(key>=arr[start] && key<=arr[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else // mid lies on second part
        {
            //left and right part
            // right part is sorted and left part is not
            if(key>=arr[mid] && key<=arr[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1; //element not found
}

// problem 2. square root using a binary search
// monotonic function-> either non decreasing/ non decreasing
// for this type of problem we can use-> binary search
int p=10; //for example
float squareRoot(int n){
    int start=0,end=n;
    float ans=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid*mid==n){
            return mid;
        }else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }else{
            end=mid-1;
        }
    }
    // to get floating part
    // start adding 0.1 and then 0.01
    float x=0.1;
    for(int i=1;i<=p;i++){ //run p times
        while(ans*ans<=n){
            ans=ans+inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
    //time complexity-> O(log n+ 10p) p is a very small number
}

// problem 3. spoj-> Aggressive cows (must solve)

