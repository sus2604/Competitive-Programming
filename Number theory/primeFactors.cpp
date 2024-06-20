// N=1e9

find all prime factors of N

// -> there can only be ont prime factor > sqrt(N)


const int MAXN=50000;

bool is_prime[MAXN];
vector<int> primes;

void prime_seive(){
    is_prime[1]=false;

    for(int i=2;i*<=MAXN;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                is_prime[j]=true;
            }
        }
    }

    for(int i=2;i<MAXN;i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

vector<int> get_prime_factors(ll q){
    vector<int> prime_factors;

    for(p:primes){
        if(q%p==0){
            prime_factors.push_back(p);

            while(q%p==0){
                q/=p;
            }
        }
        if(p*p>q) break;
    }
    if(q>1) prime_factors.push_back(q);

    return prime_factors;
}


// for a number N it has at most logN prime factors (counting all repetitons) 

// eg 28 = 2*2*7  (3 prime factors)

Let the prime factorization be n=p1⋅p2⋅...⋅pk


Then log2n=log2p1+log2p2+...+log2pk


On the right side, any term in which the prime factor is 2
has a value of 1
Since at least one prime factor is greater than 2
at least one of the terms is greater than 1
and thus the sum of the terms on the right side is greater than k


Therefore, log2n
 is equal to something greater than k
, or equivalently k<log2n

// for a number n<=1e9 number of distinct prime factors can be <= 10 
// for n<=1e18 it could be n<=18(just to be safe)
