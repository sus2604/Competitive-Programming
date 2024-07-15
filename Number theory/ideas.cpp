// given an array of size n and m queries find for each query number of triplets whose gcd=qi

n<=1e5 m<=1e5  a[i]<=1e6 qi<=1e6

// this is just pre computation to get the answer
// works for all pairs, triplets, ....,subsets
// query or no query



// build the freq array for the numbers in the array
int MAXN=1e6+5;

vector<int> cnt(MAXN,0);

for(int i=0;i<n;i++){
    cnt[a[i]]++;
}

// perform sieve operation to count the number of divisors of i are present

for(int i=0;i<MAXN;i++){
    for(int j=2*i;j<MAXN;j+=i){
        cnt[i]+=cnt[j];
    }
}

// make the nCr array eg pairs

for(int i=0;i<MAXN;i++){
    cnt[i] = (cnt[i]*(cnt[i]-1))/2;   // for pairs nC2
}

// traverse through back and subtract all the multiples


for(int i=MAXN-1;i>=0;i--){
    for(int j=2*i;j<MAXN;j+=i){
        cnt[i]-=cnt[j];
    }
}


// cnt gives all pairs with gcd 1,2,3,4,5,6,.........



// basically we performing inclusion and exclusion to get rid of all unnecessary values 
// for example for getting gcd as 2  we can get the gcd values as 4,6,8,...... so we need to subtract the following values from the possible values of gcd=2


INCLUSION AND EXCLUSION PRINCIPLE


// 1) given two numbers n and r find the number of integers in the range [1:r] that the co prime to n.

TIME COMPLEXITY : sqrt(n)

answer = total - numbers that are not co-prime with n

// so we need to calculate total numbers in range [1:r] that are non co-prime with n


int sum=0;   // total non co-prime with n

vector<int> primes;

for(int i=2;i*i<=n;i++){
    if(n%i==0){
        primes.push_back(i);
        while(n%i==0){
            n/=i;
        }
    }
}

if(n>1) primes.push_back(n);


// total number of primes <= 20

int size=primes.size();


for(int mask=1;mask<(1<<size);mask++){
    double mult=1;
    int bits=0;

    for(int i=0;i<size;i++){
        if(mask&(1<<i)){
            mult*=primes[i];
            bits++;
        }
    }
    int curr=r/mult;       // no of numbers in the range [1:r] that are divisible by mult

    if(bits%2==0){
        sum-=curr;        // inclusion and exclusion step
    }
    else sum+=curr;
}

cout<<r-sum<<endl;


// number of integers <= k which are divisible by elements of arr

// n<=15
// arr[i]<=25

ll LCM(lla,ll b){
    return (a*b)/__gcd(a,b);
}
ll cnt=0;

for(int mask=1;mask<(1<<n);mask++){
    ll lcm_val=1;
    int bits=0;

    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            bits++;
            lcm_val=LCM(lcm_val,nums[i]);
        }
    }
    ll count=k/lcm_val;

    if(bits%2==0){
        cnt-=count;
    }
    else cnt+=count;
}


// GCD and Subarrays


number of distinct gcd subarrays ending/starting at index i are log(A[i])
therefore total number of distinct gcd subarrays are N*(log(maxA[i]))

subarrays gcd is a decreasing function 
eg for array -> [6,12,18,6,3,6,12,1] -> subarray/ prefix gcd function -> [6,6,6,6,3,3,3,1]
-> hence decreasing/monotonic -> binary search can be applied

// to store all the distinct gcd subarrays for each i

vector<int> arr(n);

vector<map<int,int>> gcd_distinct(n);

/*
    Key is gcd,
    Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key.
*/

for(int i=0;i<n;i++){
    gcd_distinct[i][arr[i]]=1;

    if(i>0){
        for(auto &x:gcd_distinct[i-1]){
            int new_gcd=__gcd(arr[i],x.first);
            gcd_distinct[i][new_gcd]=max(gcd_distinct[i][new_gcd],x.second+1);
        }
    }
}


// using binary search

// doing RMQ using soarse table as it gives gcd in O(1), can use segment tree as well

// Q find the max gcd for len of subarray (k)  1<=k<=N ie for every length find the max subarray

int table[100000][20];  // len of array // number of bits in the max number ie for max(A[i])<=1e5 bitsj=20

void build_table(int arr[], int n) {  // building sparse table
    for (int i=0; i<n; i++) {
        table[i][0] = arr[i];
    }
    
    int sz = (int)log2(n);
    for (int j=1; j<=sz; j++) {
        for (int i=0; i<=n-(1<<j); i++) {
            table[i][j] = __gcd(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}

int query_table(int ql, int qr) {
    int sz = (int)log2(qr-ql+1);
    return __gcd(table[ql][sz], table[qr-(1<<sz)+1][sz]);   // returns GCD
}

int search(int curr_gcd, int begin, int end, int i) {
    if(begin == end) return end;
    int mid = (begin+end)/2;
    if(query_table(i, mid) == curr_gcd) {
        return search(curr_gcd, mid+1, end, i);   // gives first index where gcd>curr_gcd
    } else {
        return search(curr_gcd, begin, mid, i);
    }
}

void solve(int arr[], int ans[], int n) {
    build_table(arr, n);
    for(int i=0; i<n; i++) ans[i] = 1;
    
    int index, curr_gcd;
    for(int i=0; i<n; i++) {
        index = i;
        while(index < n) {
            curr_gcd = query_table(i, index);      
            if(curr_gcd <= ans[n-1-i]) break;
            index = search(curr_gcd, index+1, n, i);
            ans[index-1-i] = max(curr_gcd, ans[index-1-i]);
        }
    }
    
    for(int i=n-2; i>=0; i--) {
        ans[i] = max(ans[i], ans[i+1]);    // using decreasing property
    } return;
}


// AND and subarrays

number of distinct AND subarrays ending/starting at index i are log(maxA[i]) ie the number of bits of the number 
total number of distinct AND subarrays are N*(log(maxA[i])) 
-> subarray AND also form a decreasing function
-> hence monotonic in nature -> binary search search can be applied

-> same application for the AND subarray


// number of gcd subarrays with gcd = k

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt=0;

        int n=nums.size();

        unordered_map<int,int> prev;
        
        for(int i=0;i<n;i++){

            unordered_map<int,int> new_gcd;
            new_gcd[nums[i]]++;
            if(i>0){
                for(auto &x:prev){
                    int g=__gcd(nums[i],x.first);
                    new_gcd[g]+=x.second;
                }
            }
            cnt+=new_gcd[k];
            prev.swap(new_gcd);
        }

        return cnt;
    }
};


// total number of distinct OR subarrays (same but it forms increasing sequence)



class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<unordered_set<int>> or_sub;
        
        for(int i=0;i<n;i++){
            unordered_set<int> new_or;
            new_or.insert(arr[i]);

            if(i){
                for(int x:or_sub[i-1]){
                    int no=(x|arr[i]);
                    new_or.insert(no);
                }
            }
            or_sub.push_back(new_or);
        }

        unordered_set<int> fin;

        for(int i=0;i<n;i++){
            for(int x:or_sub[i]){
                fin.insert(x);
            }
        }

        return fin.size();
    }
};

// store all the AND subarray end points

    map<int,int> prev;
        
    for(int i=0;i<n;i++){

        map<int,int> new_and;
        
        if(i>0){
            for(auto &x:prev){
                int and=(nums[i]&x.first);
                new_gcd[and]=max(new_and[and],x.second);
            }
        }
        new_and[nums[i]]=max(new_and[nums[i]],i);
        prev=new_and;
    }

    //for each AND subarray ending at i -> we get all the AND subarrays end points



but I decided to repeat it because it ties into the previous point. Assume there are nonnegative integers a1,a2,…,an such that a1+a2+⋯+an=m. Then there are only O(sqrt(m)) distinct values among a1,a2,…,an.







