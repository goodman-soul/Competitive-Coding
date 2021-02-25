#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		int x=-1,y=-1,a=-1,b=-1;
		int arr[n][m];
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='1'){
					arr[i][j]=1;
				}else{
					arr[i][j]=0;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1){
					if(x==-1){
						x=i;y=i;
					}else{
						y=i;
					}
					if(a==-1){
						a=j;
						b=j;
					}else{
						a=min(a,j);
						b=max(b,j);
					}
				}
			}
		}
		string ans="YES";
		for(int i=x;i<=y;i++){
			for(int j=a;j<=b;j++){
				if(arr[i][j]==0){
					ans="NO";
				}
			}
		}
		cout<<ans<<endl;
	}
}