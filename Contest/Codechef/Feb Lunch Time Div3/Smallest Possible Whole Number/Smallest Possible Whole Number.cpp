#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(k==0){
			cout<<n<<endl;
		}
		else{
			ll x=n%k;
		cout<<x<<endl;
		}
	}
}