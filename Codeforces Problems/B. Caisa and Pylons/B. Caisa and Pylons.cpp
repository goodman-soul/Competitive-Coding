#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    v[0]=0;
    for(int i=1;i<=n;i++)cin>>v[i];
    int cnt=0,energy=0;
    for(int i=1;i<=n;i++){
        if(v[i]>v[i-1]){
            if(energy>=v[i]-v[i-1]){
                energy-=(v[i]-v[i-1]);
            }else{
                cnt+=v[i]-v[i-1]-energy;
                energy=0;
            }
        }else{
            energy+=(v[i-1]-v[i]);
        }
    }
    cout<<cnt<<endl;
}