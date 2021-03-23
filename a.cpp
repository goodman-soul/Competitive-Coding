#include<bits/stdc++.h>
using namespace std;
int count(int n){
    int x=0;
    while(n>0){
        x+=n/5;
        n/=5;
    }
    return x;
}
int solve(int n){
    if(n==0){
        return 0;
    }
    int start=1,prev=1,mid;
    while(true){
        if(count(start)>=n){
            ans=start;
            break;
        }else{
            prev=start;
            start*=2;
        }
    }
    if(start==prev){
        return start;
    }
    while(prev<=start){
        int mid=(start-prev)/2+prev;
        if(count(mid)>=n){
            ans=mid;
            start=mid-1;
        }else{
            prev=mid+1;
        }
    }
    return ans;
}
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}