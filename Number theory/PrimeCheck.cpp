// if a number has a factor > sqrt(N) then it also has a factor <= sqrt(N)

// O(sqrt(N))


bool isPrime(int N){
    if(N==1) return false;

    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

// sieve  O(NloglogN)

const int MAXN = 1e5;

bool prime[MAXN];    // works for n<=1e6

void fill_primes(){
    for(int i=1;i<MAXN;i++){
        prime[i]=true;
    }

    for(int i=2;i*i<MAXN;i++){
        if(prime[i]){
            for(int j=i*i;j<MAXN;j+=i){
                prime[j]=false;
            }
        }
        if(i*i>MAXN) break;
    }
}

