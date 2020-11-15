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
template<typename T,typename V> void P(pair<T,V> a){P(a.first);P(a.second);}
template<typename T> void P(vector<T> a){for(auto it:a)P(it);}

//usefull functions
inline string IntToString(ll a){string s="";while(a>0){s+=(a%10)+'0';a/=10;}return s;}
inline ll StringToInt(string s){ll a=0;int i=s.size()-1;while(i>=0){a=a*10+(s[i]-'0');i--;}return a;}
inline string lowercase(string s){int n=s.size();for(int i=0;i<n;i++){if(s[i]>='A' && s[i]<='Z')s[i]=s[i]-'A'+'a';}return s;}
inline string uppercase(string s){int n=s.size();for(int i=0;i<n;i++){if(s[i]>='a' && s[i]<='z')s[i]+='A'-'a';}return s;}

/*void dfs(vector<vector<int>> v,int x,int y,ll& val){
	if(x==v.size()-1 && y==v[x].size()-1)return;
	bool flag=false;
	if(x<v.size()-1 && y<v[x].size()-1){
		dfs(v,x+1,y,val);
		dfs(v,x,y+1,val);
	}
	if(x<v.size()-1){
		flag=true;
		//dfs(v,x+1,y,val);
		//ll sum=v[x][y]+v[x+1][y];
		ll sum=0;
		v[x][y]*=-1;v[x+1][y]*=-1;
		//ll a=v[x][y]+v[x+1][y];
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++)
			{sum+=v[i][j];}
		}
		//if(a>sum)val+=(a-sum);
		val=max(val,sum);
		//cout<<val<<endl;
		val=max(sum,val);
		dfs(v,x+1,y,val);
		
	}
	if(y<v[x].size()-1){
		//dfs(v,x,y+1,val);
		//ll sum=v[x][y]+v[x][y+1];
		v[x][y]*=-1;v[x][y+1]*=-1;
		ll sum=0;
		//ll a=v[x][y]+v[x][y+1];
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++)
			{sum+=v[i][j];}
		}
		val=max(val,sum);
		//cout<<val<<endl;
		dfs(v,x,y+1,val);
		v[x][y]*=-1;v[x][y+1]*=-1;
	}
	if(flag==true){v[x][y]*=-1;v[x+1][y]*=-1;}
}*/
/*void solve(){
	//int n,m;
	I(n);I(m);
	//ll val=0;
	vector<vector<int>> v(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;i++){cin>>v[i][j];}
	}
	//cout<<val<<endl;
	//ll val=INT_MIN;
	vector<int> row(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		//ll sum=0;
		for(int j=0;j<m;j++){
			sum+=v[i][j];
		}
		for(int j=1;j<m;j++){
			v[i][j-1]*=-1;v[i][j]*=-1;
			ll val=sum+v[i][j-1]+v[i][j-1];
			sum=max(val,sum);
		}
		row[i]=sum;sum=0;
	}
	sum=0;
	ll ans=0;
	for(int i=0;i<n;i++)ans+=row[i];
	vector<int> col(m);
	for(int i=0;i<m;i++){//col
		for(int j=0;j<n;j++)sum+=v[j][i];//j=col
		for(int j=1;j<n;j++){
			row[j]-=v[j][i];row[j-1]-=v[j-1][i];
			sum+=(v[j][i]*-1)+(v[j-1][i]*-1);
			row[j]-=v[j][i];row[j-1]-=v[j-1][i];
		}
			
	sum=0;
	
}*/
int n,m;
void solve(){
	I(n);I(m);
	vector<vector<int>>v(n,vector<int>(m));
	ll sum=0,ans=INFF;int x=0;
	FORD(i,0,n-1)FORD(j,0,m-1){
		cin>>v[i][j];
		if(v[i][j]<0)x++;
		ll y=abs(v[i][j]);
		sum+=y;
		if(ans>y)ans=y;
	}
	if(x==0)P(sum);
	else if(x%2==0)P(sum);
	else{ll a=sum-ans-ans;P(a);}
}
	
int main()
{
	int test;
	I(test);
	while(test--){
		solve();
	}
}
