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
void isP(vector<int>& x){
	bool prime[51];
	for(int i=0;i<=50;i++)prime[i]=true;
	for(int i=2;i*i<=50;i++){
		if(prime[i]){
			for(int j=i*i;j<=50;j+=i){
				prime[j]=false;
			}
		}
	}
	//vector<int> x;
	for(int i=2;i<=50;i++)if(prime[i])x.push_back(i);
}
int main()
{
	int test=1;
	//I(test);
	while(test--){
		int n,m;
		I(n);I(m);
		vector<int> x;
		isP(x);
		if(n==m){
			P("NO");
		}else{
			bool a=binary_search(x.begin(),x.end(),m);
			if(a==false)P("NO");
			else{
				int pos=lower_bound(x.begin(),x.end(),m)-x.begin();
				int b=lower_bound(x.begin(),x.end(),n)-x.begin();
				if(pos-b==1)P("YES");
				else P("NO");
			}
		}
	}
}
		
