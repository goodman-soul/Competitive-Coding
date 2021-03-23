#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
//int tolower(char ch);
//to upper(char ch);

void covert_case(string& s,char ch='l'){
	if(ch=='l')transform(s.begin(),s.end(),s.begin(),::tolower);
	else transform(s.begin(),s.end(),s.begin(),::toupper);
}
//array rotations
template<typename T>
T gcd(T n,T d){if(d==0)return n;else return (d,n%d);}
template<typename T,typename X>
void left_rotation(vector<T> &nums,X d,X n){reverse(nums.begin(),nums.begin()+d-1);reverse(nums.begin()+d,nums.end());reverse(nums.begin(),nums.end());}
template<typename T,typename V>
void right_rotation(vector<T>& nums,V d,V n){reverse(nums.begin(),nums.end());reverse(nums.begin(),nums.begin()+d-1);reverse(nums.begin()+d,nums.end());}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
 
 
long long readInt(long long l, long long r, char endd) {
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true) {
		char g=getchar();
		if(g=='-') {
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g&&g<='9') {
			x*=10;
			x+=g-'0';
			if(cnt==0) {
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
 
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd) {
			if(is_neg) {
				x=-x;
			}
			assert(l<=x&&x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l, int r, char endd) {
	string ret="";
	int cnt=0;
	while(true) {
		char g=getchar();
		assert(g!=-1);
		if(g==endd) {
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt&&cnt<=r);
	return ret;
}
long long readIntSp(long long l, long long r) {
	return readInt(l,r,' ');
}
long long readIntLn(long long l, long long r) {
	return readInt(l,r,'\n');
}
string readStringLn(int l, int r) {
	return readString(l,r,'\n');
}
string readStringSp(int l, int r) {
	return readString(l,r,' ');
}
void solve();
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=readIntLn(1,100000);
//	int t;
//	cin>>t;
	fr(i,1,t)
		solve();
	assert(getchar()==EOF);
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}
void solve(){
	cout<<"Hi";
}