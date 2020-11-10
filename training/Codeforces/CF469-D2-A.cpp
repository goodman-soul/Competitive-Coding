#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> x(n,0);
	int p;cin>>p;
	for(int i=0;i<p;i++){
		int a;cin>>a;
		x[a-1]=1;
	}
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int a;cin>>a;
		x[a-1]=1;
	}
	for(int i=0;i<n;i++){
		if(x[i]==0){cout<<"Oh, my keyboard!";return;}
	}
	cout<<"I become the guy.";
}
int main()
{
	int test=1;
	//cin>>test;
	while(test--){
		solve();
	}

}
