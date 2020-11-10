#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
	ll n,k;
	cin>>n>>k;
	ll odd=n/2;
	if(n%2==1)odd++;
	if(k>odd){
		k-=odd;
		cout<<2*k<<endl;
	}
	else{
		cout<<2*k-1<<endl;
	}
}
int main()
{
	int test=1;
	//cin>>test;
	while(test--){
		solve();
	}
}
