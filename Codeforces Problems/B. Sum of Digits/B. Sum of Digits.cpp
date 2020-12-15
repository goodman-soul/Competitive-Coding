#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void f(string& s){
    ll cnt=0;
    for(int i=0;i<s.size();i++){
        cnt+=(s[i]-'0');
    }
    s="";
    while(cnt>0){
        s+=(cnt%10)+'0';
        cnt/=10;
    }
    reverse(s.begin(),s.end());
    //cout<<s<<endl;
}
int main()
{
    string s;
    cin>>s;
    int cnt=0;
    while(s.size()>1){
        f(s);
        cnt++;
    }
    cout<<cnt<<endl;
}