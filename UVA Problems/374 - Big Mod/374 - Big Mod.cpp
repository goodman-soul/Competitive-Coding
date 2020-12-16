#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll solve(ll b,ll p, ll m)
{
    if(p==0)return 1%m;
    else if(p==1)return (b%m);
    ll t=solve(b,p/2,m) %m;
    if(p%2==0){
        return ((t%m)*(t%m)) %m;
    }else{
        return ((((t%m)*(t%m)) %m)* b)%m;
    }
}
int main()
{
    ll b,p,m;
    while(cin>>b && cin>> p && cin>> m){
        ll ans=solve(b,p,m);
        cout<<ans<<endl;
    }
}