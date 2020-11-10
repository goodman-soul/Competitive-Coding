#include<bits/stdc++.h>
using namespace std;

//integers
#define ll long long int

//take input
template<typename T> void I(T &x){
	x=0;
	bool neg=0;
	register T c=getchar();
	if(c=='-'){neg=1,c=getchar();}
	while((c<48)||(c>57))c=getchar();
	for(;c<48||c>57;c=getchar());
	for(;c>47&&c<58;c=getchar())x=(x<<3)+(x<<1)+(c & 15);
	if(neg)x*=-1;
}
template<typename T> void P(T n){
	bool neg=0;
	if(n<0)n*=-1,neg=-1;
	char sname[65];int i=0;
	do{sname[i++]=n%10+'0';n/=10;}while(n);
	--i;
	if(neg)putchar('-');
	while(i>=0)putchar(sname[i--]);
	putchar('\n');

string lower(string X){string a="";for(int i=0;i<X.size();i++)a+=tolower(X[i]); return a;}
string uppper(string X){string a="";for(int i=0;i<X.size();i++)a+=toupper(X[i]);return a;}

//bit manipulation
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_pocountll(x)
#define parity(x) __builtin_parity(x)
#define leadingzero(x) __builtin_clz(x)
#define trailingzero(x) __builtin_ctz(x)

//debug
void debug(){cout<<"Shit Life"<<E;}
void solve(){
    //cout<<setbits(3)<<endl;
    int n;I(n); 
    vector<int> v(n);
    I(v);
    P(V);
}
int main()
{
    //faster I/O in case using cin, cout
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int test=1;
    I(test);
    while(test--){
        solve();
    }
}
