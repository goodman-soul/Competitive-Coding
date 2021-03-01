#include<bits/stdc++.h>
using namespace std;

int gcd(int n,int d){
	if(d==0)return n;
	else return gcd(d,n%d);
}
void left_rotate(int arr[],int d,int n){
	d=d%n;
	int g_c_d=gcd(n,d);
	for(int i=0;i<g_c_d;i++){
		int temp=arr[i];
		int j=i+d;
		int k=i;
		while(j<n){
			arr[k]=arr[j];
			k+=d;
			j+=d;
		}
		arr[k]=temp;
	}
}
int main()
{
	int v[]={1,2,3,4,5,6,7,8,9,10,11,12};
	left_rotate(v,3,12);
	for(auto it:v)cout<<it<<" ";
}