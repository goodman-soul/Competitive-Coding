#include<bits/stdc++.h>
using namespace std;

//integers
#define ll long long int

//take input
void I(int& X){scanf("%d",&X);}
void I(ll& X){scanf("%lld",&X);};
void I(float& X){cin>>X;}
void I(vector<int>& X){for(int i=0;i<X.size();i++)scanf("%d",&X[i]);}
void I(vector<ll>& X){for(int i=0;i<X.size();i++)scanf("%lld",&X[i]);}
void I(vector<float>& X){for(int i=0;i<X.size();i++)cin>>X[i];}
void I(char& X){cin>>X;}
void I(string& X){cin>>X;}

//printing ouput
void P(){printf("\n");}
void P(int X){printf("%d",X);}
void P(ll X){printf("%lld",X);}
void P(float X){cout<<X;}
void P(vector<int> X){for(auto it:X)printf("%d",it);}
void P(vector<ll> X){for(auto it:X)printf("%lld",it);}
void P(vector<float> X){for(auto it:X)cout<<it<<endl;}
void P(char X){cout<<X;}
void P(string X){cout<<X;}

string lower(string X){string a="";for(int i=0;i<X.size();i++)a+=tolower(X[i]); return a;}
string uppper(string X){string a="";for(int i=0;i<X.size();i++)a+=toupper(X[i]);return a;}

//bit manipulation
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_pocountll(x)
#define parity(x) __builtin_parity(x)
#define leadingzero(x) __builtin_clz(x)
#define trailingzero(x) __builtin_ctz(x)

//debug
void debug(){cout<<"Shit Life\n";}
void solve(){
    //cout<<setbits(3)<<endl; 
    char x;string s;
    cin>>x>>s;
    vector<string> mat={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
    unordered_map<char,char> left,right;
    for(int i=0;i<3;i++){
	    for(int j=0;j<mat[i].size();j++){
		    if(j==0){left[mat[i][j]]=mat[i][j];right[mat[i][j]]=mat[i][j+1];}
		    else if(j==mat[i].size()-1){left[mat[i][j]]=mat[i][j-1];right[mat[i][j]]=mat[i][j];}
		    else{ left[mat[i][j]]=mat[i][j-1];right[mat[i][j]]=mat[i][j+1];}
	    }
    }
    string ans="";
    if(x=='R'){
	    for(int i=0;i<s.size();i++){
		    ans+=left[s[i]];
	    }
    }else{
	    for(int i=0;i<s.size();i++){
		    ans+=right[s[i]];
	    }
    }
    P(ans);
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
