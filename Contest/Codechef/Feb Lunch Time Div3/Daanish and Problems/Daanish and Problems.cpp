#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	int test;
	cin>>test;
	while(test--){
		vector<ll> x(10);
		for(int i=0;i<=9;i++){
			cin>>x[i];
		}
		ll k;cin>>k;
		int i=9;
		while(i>=0 && k>0){
			if(x[i]==0){
				i--;
			}else if(x[i]>k){
				x[i]-=k;
				k=0;
				i--;
			}else if(x[i]==k){
				x[i]-=k;
				k=0;
				i--;
			}else{
				k-=x[i];
				x[i]=0;
				i--;
			}
		}
		int ans=0;
		for(i=9;i>=0;i--){
			if(x[i]!=0){
				ans=i;
				break;
			}
		}
		cout<<ans+1<<endl;
	}
}