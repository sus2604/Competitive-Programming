// all primes in the range l-r

1 <= (L,R) <= 1e12  and R-L <= 1e6

const in MAXN=1e6+5;

bool is_prime[MAXN];


void sieve(){
    for(int i=2;i<MAXn;i++){
        is_prime[i]=true;
    }

    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i*i<MAXn;i++){
        if(is_prime[i]){
            for(int j=i*i;j<MAXN;j++){
                is_prime[j]=false;
            }
        }
    }
}

vector<int> generatePrimes(int N){
    sieve();

    vector<int> res;

    for(int i=2;i<=N;i++){
        if(is_prime[i]) res.push_back(i);
    }
    return res;
}

int main(){
    int l,r;

    cin>>l>>r;

    vector<int> primes=generatePrimes(sqrt(r));

    int dummy[r-l+1];

    for(int i=0;i<ril+1;i++){
        dummy[i]=1;
    }

    for(auto p:primes){
        int first_multiple = (l/i)*i;
        if(first_multiple<l) first_multiple+=p;

        for(int j=max(first_multiple,p*p);j<=r;j+=p){
            dummy[j-l]=0;
        }
    }

    for(int i=l;i<=r;i++){
        if(dummy[i-l]==1) cout<<i<<" ";
    }

    cout<<endl;

}
