#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,x;cin>>n>>x;
	bool c=false,m=false,y=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<x;j++){
			char ch;cin>>ch;
			if(ch=='C')c=true;
			else if(ch=='M')m=true;
			else if(ch=='Y')y=true;
			else continue;
		}
	}
	if(c==true || m==true || y==true)cout<<"#Color";
	else cout<<"#Black&White";
}
int main()
{
	int test=1;//cin>>test;
	while(test--){
		solve();
	}
}
