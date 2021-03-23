#include<bits/stdc++.h>
using namespace std;
string encode(string s, int k) {
    k%=26;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            int x=s[i]-'a';
            x=(x+k) %26;
            s[i]=x+'a';
        }else if(s[i]>='A' && s[i]<='Z'){
            int x=s[i]-'A';
            x=(x+k)%26;
            s[i]=x+'A';
        }
    }
    return s;
}
int main()
{
    string s;
    getline(cin,s);
    int k;
    cin>>k;
    string ans=encode(s,k);
    cout<<ans<<endl;
}