#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	cout<<abs(v[0]-v[1])<<" "<<abs(v[0]-v[v.size()-1])<<endl;
	for(int i=1;i<n-1;i++){
		cout<<min(abs(v[i-1]-v[i]),abs(v[i]-v[i+1]))<<" "<<max(abs(v[0]-v[i]),abs(v[i]-v[v.size()-1]))<<endl;
	}
	cout<<abs(v[n-1]-v[n-2])<<" "<<abs(v[0]-v[n-1])<<endl;

}
int main()
{
	int test=1;
	//cin>>test;
	while(test--){
		solve();
	}
}
