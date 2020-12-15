#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        if(n>45){
            cout<<"-1"<<endl;
        }else{
            if(n<9){cout<<n<<endl;}
            else{
                int start=9;string ans="";
                while(n>0){
                    if(n>=start){ans+=start+'0';n-=start;}
                    start--;
                }
                reverse(ans.begin(),ans.end());
                cout<<ans<<endl;
            }
        }
    }
}