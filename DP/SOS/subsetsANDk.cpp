// find the number of subsets of the array such that their AND is k.

n<=1e6 and ai<=1e6

// similar to GCD calculation of pairs,triplets,...,subsets etc.

int N=1e6+5;
vector<int> freq(1e6+5,0);

for(int i=0;i<N;i++){
    freq[arr[i]]++;
}
int bit_max=20;

for(int bit=0;bit<20;bit++){
    for(int mask=(1<<20)-1;mask>=0;mask--){
        if(mask&(1<<bit)){
            freq[mask^(1<<bit)]+=freq[mask];
        }
    }
}

// for subsets do 2^n if pairs or triplets do nCr

for(int i=0;i<N;i++){
    freq[i]=pow(2,freq[i])-1;   // this gives all subsets which have all the reqd bits+some extra bits
}

// to remove unnecessary values for each index we remove it backwards

for(int bit=0;bit<20;bit++){
    for(int mask=0;mask<(1<<20);mask++){
        if(mask&(1<<bit)){
            freq[mask^(1<<bit)]-=freq[mask];
        }
    }
}

freq[i] -> gives number of subsets with AND as i.


for general ->


const lli MLOG = 20;
const lli MAXN = (1<<MLOG);
lli dp[MAXN];  lli freq[MAXN];
void forward1(){	// adding element to all its super set
	fr(bit,MLOG)fr(i,MAXN)if(i&(1<<bit)){dp[i]+=dp[i^(1<<bit)];}}
void backward1(){	//add a[i] to a[j] if j&i = i
	fr(bit,MLOG)per(i,MAXN-1,0)if(i&(1<<bit)){dp[i]-=dp[i^(1<<bit)];}}
void forward2(){// add elements to its subsets
	fr(bit,MLOG)per(i,MAXN-1,0)if(i&(1<<bit)){dp[i^(1<<bit)]+=dp[i];}}
void backward2(){
	fr(bit,MLOG)fr(i,MAXN)if(i&(1<<bit)){dp[i^(1<<bit)]-=dp[i];}}
 
 
void solve(){
	lli n,m;
	cin>>n;
	lli mask[n];
	mset(mask,0);
	fr(i,n){
		string s;
		cin>>mask[i];
		dp[mask[i]]++;
	}
	forward2();
	fr(i,MAXN){
		dp[i]=(binpow(2,dp[i],MOD)-1+MOD)%MOD;
	}
	backward2();
	cout<<(dp[0]%MOD+MOD)%MOD<<endl;
}	

