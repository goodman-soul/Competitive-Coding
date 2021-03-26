#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// number theroy basics
void findPrimesinRange(ll n){
    // brute force solution is check every number for prime
    // if(n==1){//true}
    // else if(n==2){//false}
    // for(int i=3;i<=n;i++){
    //     // check if prime
    //     bool flag=false;
    //     for(int k=2;k<=i-1;k++){
    //         if(i%k==0){
    //             flag=true;
    //         }
    //     }
    //     if(flag==false){
    //         cout<<i<<" ";
    //     }
    // } O(n^2)

    // one optimisation canbe done is check upto n^0.5
    // for(int i=3;i<=n;i++){
    //     // check if prime
    //     bool flag=false;
    //     for(int k=2;k<=sqrt(i);k++){
    //         if(i%k==0){
    //             flag=true;
    //         }
    //     }
    //     if(flag==false){
    //         cout<<i<<" ";
    //     }
    // } time-> O(n^1.5)

    // sieve method
    bool prime[n+1]={false};
    for(int i=2;i<=n;i++){
        if(prime[i]==false){
            for(int p=i*i;p<=n;p+=i){
                prime[p]=false;
                cout<<p<<" ";
            }
        }
    }//time complexity-> O(n loglog n)
}

// problem-> given a bunch of qweries , you have to return
//  number of prime numbers in  the given range
// int main()
// {
//     int test_case();
//     cin>>test_case();// number of qweries
//     int y=pow(10,6)=1;
//     int prime[y];
//     for(int i=0;i<y;i++)prime[i]=1;
//     prime[2]=1;
//     for(int i=2;i<=n;i++){
//         if(prime[i]==1){
//             for(int p=i*i;p<=n;p+=i){ // no need to start p from i*2
//                 prime[i]=0; //because that will be previously marked as not prime
//             }
//         }
//     }
//     // create the prefix array
//     for(int i=1;i<y;i++){
//         prime[i]+=prime[i-1];
//     }
//     // give answer to the qwery
//     while(test--){
//         int a,int b;
//         cin>>a>>b;
//         cout<<prime[b]-prime[a-1]<<endl;
//     }
// }

// problem-> sieve for larger numbers
// sieve has a limitation that we can make array of O(10^8) only
// what if the number is O(10^12)

// for that case if n<=10^8 do sive method and for number >10^7
// start for 1 to sqrt(n) do prime check

// segmented sieve
void segmentedSieve(int n,int m){
    // suppose we have to find number of primes in 10^12.
    //  but we cannot make an array of 10^12.
    // but sometimes in questions a segment is given like 10^3 or 10^4
    // for that we can create the array. and do the sieve method

    // at first do sieve for 10^6
    //  then with the help of those primes for each
    // qwery do the following

    // we can build this sieve for all qwerues
    const int N=10000;int p[N+1]={0};
    vector<int> primes;
    for(int i=0;i<=N;i++){
        if(p[i]==0){
            primes.push_back(i);
            for(int j=i*i;j<=N;j+=i){
                p[j]=1;
            }
        }
    }
    // range [m,n];
    bool segment[n-m+1];
    for(int i=0;i<n-m+1;i++)segment[i]=0;
    // [0,0,0,0,0,0] -> kind of shifted version
    // how to get first multiple of prime number thats closest to m
    // -> (m/o)*p to get starting point

    for(auto x:primes){
        // stopping point
        if(x*x>n){
            break; // no need to check after that
        }
        // starting point
        int start=(m/x)*x;
        // corner case
        if(x>=m && x<=n){
            // prime number lies in a segmented sieve range
            start=x*2;
        }
        // mark all multiples of x in range that are not prime
        for(int i=start;i<=start;i+=x){
            segment[i-m]=1; //as it is shifted version
        }
        // now there is one corner case
        //  suppose there is overlapping of arrays
        // prime number=[3,5,7,11..]
        // and the range is [3, 100] then there is a problem
        for(int i=m;i<=n;i++){
            if(segment[i-m]==1 && i!=1){
                cout<<i<<" ";
            }
        }
    }
}

// prime factorization of numbers using sieve method
// useful when you have lot of qweries
// O(log n) time for each qwery if ignore pre computation
void generatePrimefactor(int n,vector<int>& primes){
    vector<int> factors;
    factors.clear(); //empty vector
    int i=0;
    int p=primes[0];
    while(p*p<=n){
        if(n % p==0){
            factors.push_back(p);
            while(n%p==0){
                n/=p;
            }
        }
        i+=1;
        p=primes[i];
    }
    if(n!=1){
        factors.push_back(n);
    }
    for(int i=0;i<(int)factors.size();i++){
        cout<<factors[i]<<" ";
    }
} // we can store the count of each factors using pairs


// prime factorizations trail divisions
void primeFactors(int n){
    // for every step we have to go upto sqrt(n)
    vector<pair<int,int>> factors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                count++;
            }
            factors.push_back(make_pair(i,count));
        }
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }
    for(auto it: factors){
        cout<<it.first<<"^"<<it.second<<endl;
    }
} //time complexity-> O(sqrt(n))

// problems-> count number of divisions using sieve method

// factorial problems
// gcd algorithm by euclid
