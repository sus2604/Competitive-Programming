const int p=31;
const int mod=1e9+7;
const int MAXN=1e5+5;   // string length
ll pw[MAXN];
ll inv[MAXN];
ll hash[MAXN];            // prefix hash
ll reverse_hash[MAXN];  // suffix hash
ll rev_pre_hash[MAXN];
ll power(ll a,ll b){
    if(b==0){
        return 1LL;
    }

    ll x=power(a,b/2);
    ll ans=1;

    if(b%2){
        ans=(x*x)%mod;
        ans=(ans*a)%mod;
    }
    else ans=(x*x)%mod;

    return ans;
}

ll inverse(ll A){
    return power(A,mod-2);
}

void pre_calc(){
    pw[0]=1;
    for(int i=1;i<MAXN;i++){
        pw[i]=(pw[i-1]*p)%mod;
    }

    ll pw_inv = inverse(p);
    inv[0]=1;

    for(int i=1;i<MAXN;i++){
        inv[i]=(inv[i-1]*pw_inv)%mod;
    }
}

ll quickHash(const string& str){
    ll hash=0;

    int n=str.size();
    ll p_pow=1;
    for(int i=0;i<n;i++){
        hash=(hash+(str[i]-'a'+1)*p_pow)%mod;
        p_pow=(p_pow*p)%mod;
    }
    return hash;
}

void build(const string& str){
    ll ans=0;

    int n=str.size();
    ll p_pow=1;
    for(int i=0;i<n;i++){
        ans=(ans+(str[i]-'a'+1)*p_pow)%mod;
        p_pow=(p_pow*p)%mod;
        hash[i]=ans;
    }

    ans=0;
    p_pow=1;
    for(int i=n-1;i>=0;i--){
        ans=(ans+(str[i]-'a'+1)*p_pow)%mod;
        p_pow=(p_pow*p)%mod;
        reverse_hash[i]=ans;
    }

    ans=0;
    for(int i=n-1;i>=0;i--){
        ans=((ans*p)%mod+(str[i]-'a'+1))%mod;
        rev_pre_hash[i]=ans;
    }
}

ll substring_hash(const string& str,int i,int j){
    if(i==0){
        return hash[j]%mod;  
    }
    else{
        ll ans = (hash[j]-hash[i-1]+mod)%mod;

        return (ans*inv[i-1])%mod;
    }
}