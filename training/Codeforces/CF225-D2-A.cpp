#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
long long INFF = 1000000000000000005LL;
#define FORD(i,j,k) for(int i=j;i<=k;i++)
#define BACK(i,j,k) for(int i=k;i>=j;i--)
//reading
template<typename T> void I(T &a){cin>>a;};
template<typename T,typename V> void I(pair<T,V>& a){I(a.first);I(a.second);}
template<typename T> void I(vector<T>& v,int n){T temp;for(int i=0;i<n;i++){I(temp);v.push_back(temp);};}


//printing
template<typename T> void P(T a){cout<<a<<" ";}
//template<typename T,template V> void P(pair<T,V> a){P(a.first);P(a.second);}
template<typename T> void P(vector<T> a){for(auto it:a)P(it);}

//usefull functions
inline string IntToString(ll a){string s="";while(a>0){s+=(a%10)+'0';a/=10;}return s;}
inline ll StringToInt(string s){ll a=0;int i=s.size()-1;while(i>=0){a=a*10+(s[i]-'0');i--;}return a;}
inline string lowercase(string s){int n=s.size();for(int i=0;i<n;i++){if(s[i]>='A' && s[i]<='Z')s[i]=s[i]-'A'+'a';}return s;}
inline string uppercase(string s){int n=s.size();for(int i=0;i<n;i++){if(s[i]>='a' && s[i]<='z')s[i]+='A'-'a';}return s;}

int main()
{
	int n;I(n);
	int top;I(top);
	bool flag=false;
	while(n--){
		int left,right;I(left);I(right);
		bool pos[7];for(int i=0;i<=6;i++)pos[i]=false;
		if(pos[top]==false)pos[top]=true;
		else flag=true;
		if(pos[7-top]==false){pos[7-top]=true;top=7-top;}
		else flag=true;
		if(pos[left]==false){pos[left]=true;}
		else flag=true;
		if(pos[right]==false)pos[right]=true;
		else flag=true;
		if(pos[7-right]==false)pos[7-right]=true;
		else flag=true;
		if(pos[7-left]==false)pos[7-left]=true;
		else flag=true;
	}
	if(flag==false)P("YES");
	else P("NO");
}
