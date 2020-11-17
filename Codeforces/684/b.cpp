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

void solve(){
	int n,k;I(n);I(k);
	vector<ll> v(n*k);
	for(int i=0;i<n*k;i++)I(v[i]);
	int pos=n/2;
	if(n%2==0)pos--;
	if(pos==0){
		ll ans=0;
		int count=0;
		for(int i=pos;i<n*k;i+=n){
			if(count<k){ans+=v[i];count++;}
		}
		P(ans);cout<<endl;
	}else{
		int left=n-pos;
		ll ans=0;
		int count=0;
		for(int i=n*k-left;i>=0;i-=left){
			if(count<k){ans+=v[i];count++;}
		}
		P(ans);cout<<endl;
	}
}
int main()
{
	int test;
	I(test);
	while(test--){
		solve();
	}
}
