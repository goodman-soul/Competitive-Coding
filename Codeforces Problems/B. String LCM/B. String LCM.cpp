#include<bits/stdc++.h>
using namespace std;
int main()
{
	auto func=[](string s,int k)->string{
		string result="";
		while(k--){
			result+=s;
		}
		return s;
	};
	int test;
	cin>>test;
	while(test--){
		string s,t;
		cin>>s>>t;
		int n=s.size(),m=t.size();
		int g=__gcd(n,m);
		if(func(s,m/g)==func(t,n/g)){
			cout<<func(s,m/g)<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
}
