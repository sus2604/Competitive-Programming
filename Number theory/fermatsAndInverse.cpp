// a^(p-1) % p = 1

a^(p-1) % p = 1
a^(p) % p = a
a^(p+1) % p = a^2
a^(p+2) % p = a^3 ............  cyclic repetition

// p -> prime
// a%p!=0  1<=a<=p-1

//x = (1/a) % p

//(x*a) % p = 1

// => inv(a) = power(a,p-2)   // a^-1

// ==> (a/b) % mod => (a*power(b,mod-2))%mod
#define ll long long
int mod=1e9+7;

ll add(ll x, ll y)  { return (x%mod + y%mod)%mod; }
ll sub(ll x, ll y)  { return (x%mod - y%mod + mod)%mod;}
ll mul(ll x, ll y)  { return (x%mod * y%mod)%mod; }

const int MAXN=5e5+5;
ll factorial[MAXN];
ll inverse_factorial[MAXN];

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

ll binexp(ll a,ll b){
    ll res = 1;
    while(b){
    if(b&1)res = ((res%mod)*(a%mod)%mod);
    a = ((a%mod)*(a%mod)%mod);
    b>>=1LL;
    }
    return res%mod;
}

ll inverse(ll A){
    return binexp(A%mod,mod-2);
}

void precompute_factorials() {
    factorial[0]=1;
    for(int i=1;i<MAXN;i++){
        factorial[i]=mul(factorial[i-1],i);
    }
    for(int i=0;i<MAXN;i++){
        inverse_factorial[i]=(inverse(factorial[i]));
    }
}

ll fac(ll N){
    ll ans=1;
    for(int i=1;i<=N;i++){
        ans=(ans*i)%mod;
    }
    return ans;
}

ll nCr(ll n,ll r){
    ll nfact=factorial[n];
    ll irfact=inverse_factorial[r];
    ll inrfact=inverse_factorial[n-r];
    ll ans = mul(nfact,irfact);
    ans = mul(ans,inrfact);

    return ans;
}






