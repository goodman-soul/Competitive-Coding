#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left=n/2,right=n/2;
    if(n%2==0){
        left-=1;//right-=1;
    }
    vector<char> ans(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(left==right){
            ans[left]=s[i];
            left--;right++;
        }else if(flag==false){
            if(left>=0){
                ans[left--]=s[i];
            }flag=true;
        }else if(flag==true){
            if(right<=n){
                ans[right++]=s[i];
            }flag=false;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i];
    cout<<endl;
}