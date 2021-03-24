// bit manipulations
#include<bits/stdc++.h>
using namespace std;
// bitwise and, or, not ,xor
// &, |, ~, ^

// AND Gate
// 1&1=1 , A&0=0
// OR Gate
// 0|0=0, A | 1=A

// and or are binary operators
// a&b=c-> 5=00000101
//         7=00000111-> doing and 00000101
// similary we can perform or

// XOR-> exclusive or
// 1^1=0 and 0^0=1-> exactly one of the bit is one
// 5^7=2
// xor of same number is 0
// xor of any number with 0-> that number

// NOT operator
// flip all bits
// ~1=0 and ~0=1

// shift operator-> 1. left << and 2. right>>
// shift-> binary operator 5<<1-> left shift all bits by one position
// a<<1-> a*2________ 5<<a-> 5*pow(2,a);
// right shift performs division 

// given n-> if is odd or even or not
bool evenOdd(int num){
    // if the last bit is 1-> odd number else even number
    if(n&1){
        return true; //number is odd;
    }else return false; // number is even
}

// problem unique umber->
// given a list of numbers where every number is occuring twice except one
// number. find that number
int findUniqueNumber(int arr[],int n){
// concept-> xor of same two number=0 and 0^A=A;
    int num=arr[0];
    for(int i=1;i<n;i++) //time->O(n) and O(1) space
        num^=arr[i];
    }
    return num;
}
// we want to extract the bit at ith position
int getbitFromRight(int n,int i){
    // position is from right
    // create a mask and then do bitwise and
    int mask=i<<i;
    int bit=(n & mask)>0 ?1:0; 
    return bit;
}
// we want to set a perticular bit
void setBitFromRight(int &n,int i){
    // set ith bit
    // concept-> we can do create a mask(ith position contain 1)
    // and perform or operation-> ith bit will be 1
    int mask=1<<i;
    n=n|mask;
}

void clearBitFromRight(int &n,int i){
    // clear ith bit from right
    // we need to create a mask where ith bit of the mask is 0
    // all other bit is one
    int mask=~(1<<i);
    // at first-> 0000100000 then negete-> 1111011111
    n=n & mask;
}

void updateBitFromRight(int &n,int i,int b){
    // b value of bit
    // clear the bit of n at ith position
    // then create a mask
    int mask=~(i<i); 
    int clearedBit = n & mask; //clearing the ith bit of n
    n = clearedBit | (b<i); // n | 000b00000
    // brackets are recommended
}

// Problem-> Clear Range of bits
// given a position n-> clear all i bits from the right
int clearAllBitsFromRight(int n,int i){
    // 01011011010 clear 3 bits(i=3)-> 01011010000
    // cout<<(~0)->-1
    // store all 1s
    // then left shif by i postion-> create the mask;
    int mask=-1<<i;
    n = n & mask;
    return n;
}

int clearAllBitsInRange(int n,int i,int j){
    // clear all the bits from i to j
    // take right most is 0 indexed
    // create a mask that have 0 form i to j and 1 for other places
    // 111100001111-> something like this
    // 111100000000-> left part
    // or 000000001111(right part)-> we can get the mask
    int leftPart=(~0) << (j+1); //111100000
    int rightPart=(1<<i)-1;
    int mask=a|b;
    return n & mask;
}

// you are given two 32 bit number N and M and a range(i,j)
// write a method to set all bits between i and j in N equal to M
// (i.e,M becomes a substring of N located in i to j)
// place m inside n of index i to j(from right)

void convertSomePart_M_to_N(int m,int n,int i,int j){
    // clear the bits (i,j) of n
    n=clearAllBitsInRange(n,i,j);
    // left shift m by i places and then do or opration
    return n|(m<<i);
}

// count of set bits in a number
int noOfSetbits(int n){
    // simple mod approach
    // int count=0;
    // while(n>0){
    //     count+=n&1;
    //     n=n>>1;
    // }return count;// time->O(log n)
    // second method
    int count=0;
    while(n>0){
        n=n & (n-1);// remove bits from right to left all the set bits
        count++;
    }return count; // O(set bits)->O(log n)

    // or use an built in methods
    // return __builtin_popcount(n);
}

//decimal to binary
void decimalToBinary(int n){
    // bydefault its stored in binary
    while(n>0){
        int bits=(n&1);
        cout<<bits<<" ";
        n=n>>1;
    }//prints in reverse of the binary rep
    // to print in right formation-> convert that in decimal rep
    int ans=0;
    int p=1;
    while(n>0){
        int bit=(n&1);
        ans+=p*bits;
        n=n>>1;
        p*=10;
    }
    cout<<ans<<endl;
}

// unique number-2
// you are given n intergers where every number is repeated 
// except two number. find two numbers in o(n) time and O(1) space
void findTwoUniqueNumbers(int arr[],int n){
    // use bitwise operators
    // [1,1,2,3,5,2,5,7]-> unique numbers are 3, 7
    // do the xor of all elements we will get 3^7=a
    // one important obeservation is that-> this xor can never be zero
    // or atleast one setbit-> find out that setbit
    // create a mask-> and find out which of the elements have a setbit in that position
    // one of values will satisfy that condition
    // then do the xor of those values-> will get one ans;
    // xor with a-> get the second ans;

    int num=arr[0];
    for(int i=1;i<n;i++){
        num^=arr[i];
    }
    int x=num,position=0;
    // position of 1st set bit form right in num
    while(x&1){
        position++;
        x=x>>1;
    }
    // create a mask
    int mask=1<<position;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i] & mask>0){
            ans^=a[i];
        }
    } //give one of the ans;
    int y=num^ans; //another ans
    cout<<ans<<" "<<y<<endl;   
}

// unique number-3
// given array of n numbers. all elements are occuring three times.
// one element occures one time. You have to find out the only number
int findOnlyOccuringNumber(int arr[],int n){
    // [1,1,1,2,2,2,3]-> 3
    // numbers will be suffled(not in sorted order)
    // cannot use the xor approach previously discussed 
    // we need to find a way to cancel three times occuring element

    // convert all the numbers in binary
    // for each index-> store something like this

    // 3-> 011
    // 3-> 011
    // 2-> 010
    // 1-> 001
    // 1-> 001
    // 3-> 011
    // --------
    // for each position calculate the sum-> 0 4 6
    // remember we can have only 64 bit numbers-> take a 64 bit array> store the frequency

    // take a note that those frequencies those will of form 3n or 3n+1
    // then do %3-> then convert that array into decimal-> we can get that value

    // this concept canbe extended to 3n,5n,7n...

    int v[65]={0};
    for(int i=0;i<n;i++){
        int num=arr[i];
        int pos=0;
        while(num&1){
            v[pos++]+=num&1;
            num=num>>1;
        }
    }
    int ans=0;
    for(int i=0;i<64;i++){
        v[i]%=3;
        ans+=pow(2,i) *v[i];
    }
    return ans;
}
int main()
{
    int arr[]={1,1,1,2,2,2,3};
    cout<<findOnlyOccuringNumber(arr,7)<<endl;
}

// fast exponentation
// compute pow(a,n)

int fastExponentiationPower(int a,int b){
    int ans=1;
    while(b>0){
        int bit=n&1;
        if(bit==1){
            ans=ans*a;
        }
        a=a*a;// every time we go to next bit postion we will square up the value
        n=n>>1;//discard the last bit of n
    }
    return ans;
}

void findingSubsetOfString(char a[i]){
    // subsequence-> for every character we have two option
    // there will be 2^n number of subsets
    auto filter=[](int n,char a[]){
        int j=0;
        while(n>0){
            int bit=(n&1);
            if(bit){
                cout<<a[j];
            }
            j++;
            n=n>>1;
        }
    };// this function matches the pattern with the string
    int n=strlen(a);
    for(int i=0;i<(1<<n);i++){
        filter(i,a);
    }
}

// important-> inclusion & exclusion principle using bit masks