#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos;
    cin>>n>>pos;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    //pos-=1;
    int cnt=0;
    int left=pos-1,right=pos-1;
    while(left>=0 && right<n){
        if(left==right){
            if(v[pos-1]==1){cnt++;}
            left--;right++;
        }else{
            if(v[left]==1 && v[right]==1){cnt+=2;}
            left--;right++;
        }
    }
    while(left>=0){
        if(v[left]==1){cnt++;}
        left--;
    }
    while(right<n){
        if(v[right]==1){cnt++;}
        right++;
    }
    cout<<cnt<<endl;
}