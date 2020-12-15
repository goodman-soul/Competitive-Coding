#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(pair<ll,ll>p1,pair<ll,ll> p2){
    if(p1.second==p2.second){
        return p1.first>p1.first;
    }
    return p1.second>p2.second;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> v;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),f);
    ll cnt=0;
    ll start=0;
    while(start<m && n>0){
        if(v[start].first<=n){
            cnt+=v[start].second * v[start].first;
            n-=v[start].first;
            start++;
        }else{
            cnt+=v[start].second * n;
            n=0;
        }
    }
    cout<<cnt<<endl;

}