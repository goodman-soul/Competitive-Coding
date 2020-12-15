#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;string s;
        cin>>n>>s;
        if(n<4){
            cout<<"NO"<<endl;
        }else if(n==4){
            if(s=="2020")cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            if(s[0]=='2'){
                if(s[1]=='0'){
                    if(s[2]=='2'){
                        if(s[3]=='0')cout<<"YES"<<endl;
                        else if(s[n-1]=='0')cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
                    }else if(s[n-2]=='2'){
                        if(s[n-1]=='0')cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
                    }else{
                        cout<<"NO"<<endl;
                    }
                }else if(s[n-3]=='0'){
                    if(s[n-2]=='2'){
                        if(s[n-1]=='0')cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
                    }else cout<<"NO"<<endl;
                }else cout<<"NO"<<endl;
            }else if(s[n-4]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0'){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }
    }
}