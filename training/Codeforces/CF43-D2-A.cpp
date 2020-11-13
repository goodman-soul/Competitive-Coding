#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a=-1;string y="";
	unordered_map<string,int> mp;
	for(int i=0;i<n;i++){
		string x;cin>>x;
		mp[x]++;
		if(mp[x]>a){
			y=x;a=mp[x];
		}
	}
	cout<<y;
}
int main()
{
	int test=1;
	while(test--){
		solve();
	}
}
