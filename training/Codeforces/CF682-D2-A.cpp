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
	ll n,m;I(n);I(m);ll ans=0;
	if(n+m<5){P(0);return 0;}
	for(int i=1;i<=min(n,m);i++){
		ll a=i%5;//cout<<"Fuck"<<endl;
		ll x=5-a;//bool flag=false;
		//if(x==0)flag=true;
		ll count=0;
		if(max(n,m)>=x)count=(max(n,m)-x)/5+1;
		//if(flag==true)count--;
		ans+=count;
	}
	P(ans);
}
