#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;string s;
	cin>>s;
	transform(s.begin(),s.end(),s.begin(),::tolower);
	unordered_map<char,bool> mp;
	for(int i=0;i<26;i++)mp['a'+i]=true;
	for(int i=0;i<n;i++){
		mp[s[i]]=false;
	}
	for(auto it: mp){
		if(it.second==true){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}

int main()
{
	int test=1;
	//cin>>test;
	while(test--){
		solve();
	}
}
