#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s,x;
	cin>>s>>x;
	if(s==x)cout<<"-1"<<endl;
	else{
		cout<<max(s.size(),x.size())<<endl;
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
