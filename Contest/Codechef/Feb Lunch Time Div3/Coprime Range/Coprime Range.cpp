#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int arr[26];
		for(int i=0;i<26;i++){
			arr[i]=0;
		}
		for(int i=0;i<(int)s.size();i++){
			arr[s[i]-'a']++;
		}
		vector<int> v;
		for(int i=0;i<26;i++){
			if(arr[i]!=0){
				v.push_back(arr[i]);
			}
		}
		sort(v.begin(),v.end());
		string ans="YES";
		int index=lower_bound(v.begin(),v.end(),2)-v.begin();
		if(index==v.size()){
			ans="NO";
		}else{
			for(int i=0;i<(int)v.size();i++){
				if(v[i]==1){
					if(index<=v.size()-1){
						if(v[index]>=2){
							v[i]+=2;
							v[index]-=2;
							if(v[index]<2){
								index++;
							}
						}
						//v[i]+=2;
						
					}else{
						ans="NO";
					}
				}
			}
		}
		// for(int i=0;i<(int)v.size()-1;i++){
		// 	if(v[i]==1){
		// 		v[i]+=2;
		// 	}
		// }
		//string ans="YES";
		for(int i=0;i<(int)v.size();i++){
			//cout<<v[i]<<" ";
			if(v[i]==1){
				ans="NO";
			}
		}
		cout<<ans<<endl;
	}
}