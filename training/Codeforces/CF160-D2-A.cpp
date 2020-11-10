#include<bits/stdc++.h>
using namespace std;
void I(int& X){scanf("%d",&X);}
void I(vector<int>& X){for(int i=0;i<X.size();i++)scanf("%d",&X[i]);}
void P(int X){printf("%d",X);}
void solve(){
	int n;
	I(n);
	vector<int> v(n);
	I(v);
	sort(v.begin(),v.end(),greater<int>());
	int sum=0;
	for(int i=0;i<n;i++)sum+=v[i];
	int coin=0;
	int x=0;
	for(int i=0;i<n;i++){
		x+=v[i];
		coin++;
		if(x>sum-x){P(coin);return;}
	}
	P(-1);
}

int main()
{
	int test=1;
	//I(test);
	while(test--){
		solve();
	}
}
