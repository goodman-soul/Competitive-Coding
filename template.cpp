#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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

//main function
int main()
{
	vector<long long int> v={1,2,3,4,5,6,7,8,9,10,11,12};
	left_rotation(v,3,12);
	for(int i=0;i<12;i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	right_rotation(v,3,12);
	for(int i=0;i<12;i++){
		cout<<v[i]<<" ";
	}
}