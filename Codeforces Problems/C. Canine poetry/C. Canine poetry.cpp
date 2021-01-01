#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n;
		cin>>n;
		while(n--){
				string s;
				cin>>s;
				unordered_map<char,bool> st;
				for(auto it:s)st[it]=true; //characters present
				unordered_map<char,bool> another; //chars canbe added
				vector<char> charset;
				for(int i=0;i<26;i++){
						if(st.find('a'+i)==st.end()){
								another['a'+i]=true;
								charset.push_back('a'+i);
						}
				}
				int start=0;int cnt=0;
				int size=(int)s.size();
				int left=size/2,right=size/2;
				while(left>=0 && right<size){
						if(left==right){
								left--;
								right++;
						}else{
								if(s[left]==s[right]){
										cnt++;
								}
								left--;right++;
						}
				}bool flag=false;
				while(left>=0){
						right=size-1;
						if(s[left]==s[right])cnt++;
						left--;
						flag=true;
				}
				if(flag==false){
						while(right<size){
								left=0;
								if(s[left]==s[right])cnt++;
								right++;
						}
				}
				cout<<cnt<<endl;
		}
}



