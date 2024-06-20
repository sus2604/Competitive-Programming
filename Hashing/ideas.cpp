// LCS using hashing

using binary search on answer using the length as answer

// can be done in O(nlogn)



// Rabin Karp Algorithm

check hash values for pattern length string ans compare



// find out the lexicographical smallest cyclic shift of the string
// find the order of the different cyclic shifts (sorted order)

double the string by appending the string to same string
-> this gives all cyclic shifts as the substrings of length n
-> compare two strings starting at i and j cmp(i,j)
-> to compare two strings lexicographically we need to check the first element after longest common prefix for both the strings
-> use binary search to get the common prefix and then compare the next element

bool cmp(int i,int j){
    int l=1;
    int r=n;
    int ans=0;

    while(l<=r){
        int mid=(l+r)/2;
        if(substring_hash(i,i+mid-1)==substring_hash(j,j+mid-1)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    if(ans==1) return 0;
    else return s[i+ans]<s[j+ans];
}
string s;
s=s+s;

vector<int> idx;

for(int i=0;i<n;i++) idx.push_back(i);

sort(idx.begin(),idx.end(),cmp);



// given a string s, find the largest substring which occurs at-least twice in the string

using binary search on answer we can get the length by comparing substring hash of the answer length



// given a string s and q queries of the form [li,ri] tell if s[li,ri] is a palindrome or not?


generate reverse hash as well to check if front and reverse hash are equal for the range 


// find the longest palindromic substring

-> apply binary search on answer for length 
-> 2 binary search will be applied for even and off length answer
-> manacher can also be used to solve the question


// find the minimum number of characters to append at end and it becomes a palindrome

-> just find the largest palindrome ending at the end 
-> to do this rev(s) + "#" + s find last element of prefix array we get the palindrome length


// period of a string


-> smallest monomer to connect to get the whole string 

period  = N - LPS[N-1]












