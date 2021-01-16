#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;
	for(int tt=1;tt<=test;tt++){
		int n,d;
		cin>>n>>d;
		vector<int> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		sort(v.begin(),v.end());
		string ans="NO";
		if(v[n-1]<=d || v[0]+v[1]<=d){
			ans="YES";
		}cout<<ans<<endl;
	}
}
