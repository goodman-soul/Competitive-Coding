// character arrays
char a[100];
char a[]={'a','b','c'}; // charcter array is of size 3

// null character for character array
// null character -> ASCHII value 0

// for character arrays
// cout<<a<<endl;-> we will get the whole character array
(opertor overloading)

char s[10];
cin>>s; // null character will automatically added

// ------> read a sentence
cin.get() // reads a single character


void readLine(char a[],int maxLen, char delim='\n'){
    int i=0;
    char ch=cin.get();
    while(ch!=delim){ //read untill i get a delimiter
        a[i]=ch;
        i++;
        if(i==maxLen-1){
            break;
        }
        ch=cin.get();
    }
    a[i]='\0';
    return;
}

cin.getline(a,1000,'\n'/*->delimiter*/);
character array, maxLen and delimiter

//check a string is palindrome or not

// remove consecutive duplicates in a string
// without an extra array. -> O(n) time and O(1) space
void function(char a[],int n){
    int l=strlen(a);
    if(l==1 or l==0){
        return;
    }
    int prev=0;
    for(int current=1;current<l;current++){
        if(a[current]!=a[prev]){
            prev++;
            a[prev]=a[current];
        }
    }
    a[prev+1]='\0';
    return;
}

//find the largest string-> for efficient store only 
// current and longest string-> dont consider the spaces


C++ STL String class
// wraps a character array in a container
#include<string>
string s0;
string s1("Hello");
string s2="Hello World";
string s3(s2); //copied 
string s4=s3 //another way to copy

char a[]={'a','b'};
string s5(a); //s5="ab";

if(s0.empty()){}//returns boolean value
s0.append("I eat");// append 
s0+=s1; // another way to append
//remove or erase
s0.clear(); //erase all the contents
s0.length() //length of two strings

s1.compare(s2)//compare two strings->return 0, or less than 0 or greater than 0
// < > == ->overloaded for strings

// find the index
s1="I want to find mango"
int index=s1.find("mango");
//remove a word from string
s.erase(index,word.length()); //strating index and length

//iterate over the characters
for(int i=0;i<l.length();i++){}
//iterators
for(auto it:s.begin();it!=s.end();it++){
    cout<<*it<<endl;
}
for(auto it:s){}//another way to iterate

//string sorting
// list of strings amd we want to sort them
// comparator function

//string tokeniser //breaking char array wrt delimiter
#include<cstring>
//char *strtok(char *s,string_delimiter)
// creates an array & the pointer will point to the first token
// to retrieve all other token we need to pass something like this
ptr=strtok(NULL,' ');
//strtok maintains the static variable, maintains the state of the string internally

char s[1000]="Today is rainy day";
char *ptr=strtok(s,' '); //pointing to the first token
ptr=strtok(NULL,' ');
// after entire string ptr retuns null
// we can break wrt any string delimiter

// ___________________________
// design string tokeniser
// we will use dynamic array
// maintain a variable to maintain the state->must be a static variable

char *mystrtok(char *str,char delim){
    //string char that act as a delim
    static char *input=NULL;
    if(str!=NULL){
        input=str;
    }
    //check here;
    if(input==NULL){ //after the final token
        return NULL; //to stop the  tokeniser;
    }
    //start extracting tokens and store them in array
    char *output=new char(strlen(input)+1);
    int i=0;
    for(;input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i]=input[i];
        }else{
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    //corner case for last token we maynot contain the space
    output[i]='\0';
    input=NULL;
    return output;
}

//