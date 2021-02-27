#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	auto foo=[](vector<ll> v)->bool{
		for(int i=1;i<(int)v.size();i++){
			if(v[i-1]<v[i]){
				return false;
			}
		}
		return true;
	};
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(foo(v)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
}