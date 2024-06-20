// same as number of subsets with OR = K

// atcoder abc f 349


vector<int> a(n);
int k;

vector<int> rest;

for(int i=0;i<n;i++){
    if(a[i]%k==0) rest.push_back(a[i]);
}

// prime factorization of k in O(sqrt(k))
ll k_mask=0;

map<int,pair<int,int>> mp;
int idx=0;

for(int i=2;i*i<=k;i++){
    int cnt=0;
    while(k%i==0){
        cnt++;
        k/=i;
    }
    if(cnt>0) mp[i]={cnt,idx};
    idx++;
}
if(k>1) mp[k]={1,idx};

// creating bitmask for the array rest

auto getMask=[&](ll num) {
    ll mask = 0;
    for(auto x:mp){
        int cnt=0;
        int p=x.F;
        int p_cnt=x.S,F;
        int p_idx=x.S.S;
        while(num%p==0){
            cnt++;
            num/=p;
        }
        if(cnt==p_cnt){
            mask|=(1<<(p_idx));
        }
    }
    return mask;
}
int N=1e6+1;

vector<ll> freq(N,0);

for(int i=0;i<rest.size();i++){
    
    ll mask=getMask(rest[i]);
    freq[mask]++;
}

// all subsets with OR=k;
int bit_max=mp.size();

for(int i=0;i<bit_max;i++){
    for(int mask=0;mask<(1<<bit_max);i++){
        if(mask&(1<<i)){
            freq[mask]+=freq[mask^(1<<i)];     // forward
        }
    }
}


for(int i=0;i<N;i++){
    freq[i]=pow(2,freq[i])-1;
}

for(int i=0;i<bit_nax;i++){
    for(int mask=(1<<bit_max)-1;i>=0;i--){
        if(mask&(1<<i)){
            freq[mask]-=freq[mask^(1<<i)];     // backward
        }
    }
}


cout<<freq[k]<<endl;








