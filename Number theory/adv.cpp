// linear sieve

const int N = 10000000;
vector<int> lp(N+1,0);   // gives the lowest primes for each number
vector<int> pr;        // lists all primes till N

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}

// multiplicative function

f(mn)=f(m)f(n) -> if m and n are co prime

properties -> 

f(1)=1
h(n)=f(n)g(n) , then h(n) is also multiplicative, iff f(n) and g(n) are multiplicative

Dirichlet convolution

f*g(n) = for all (d/n) [sum(f(d)g(n/d))]

-> if f and g are multiplicative then (f*g) is also multiplicative   // imp

g(n)=1 is multiplicative -> f*g(n) = for all (d/n) [sum(f(d))]
=> corollary ->  for all (d/n) sum(f(d)) is also  multiplicative if f(n) is multiplicative
// agar andar wala multiplicative h toh pura sum multiplicative h   // imp

eg given N=1e18 find the sum of ETF all divisors of N.

if n=10 ans = ETF(1)+ETF(2)+ETF(5)+ETF(10)

let f(n) = for all (d/n) sum(ETF(d)) -> since ETF is multiplicative -> f(n) is multiplicative

=> it can be proved that f(n) = n (always)  // for inside function as ETF


// list of Multiplicative functions

-> ETF
-> f(n)=1
-> f(n)=n 
-> number of divisors Nd(x) -> Nd(1)=1
                            -> Nd(p)=2
                            -> Nd(p^k)=k+1
                            -> Nd(x)=(k1+1)(k2+1)(k3+1)....  (using Prime factorization)

-> sum of (divisors)^k for any k -> sum of GP formula
-> mobius function -> 1 if number of prime factors is even 
                   -> -1 if number of prime factors is odd
                   -> 0 if number is not square free


https://codeforces.com/blog/entry/53925


// storing values of MF using seive

-> for mobius function 

vector<int> mu(N+1);
vector<bool> is_prime(N+1,true);
is_prime[0]=is_prime[1]=false;
mu[1]=1;

for(int i=2;i<=N;i++){
    for(int j=i;j<=N;j+=i){
        if(j>i) is_prime[j]=false;
        if(j%(i*i)==0) mu[j]=0;
        mu[j]=-mu[j];
    }
}

-> for ETF function 

void phi_1_to_n(int n) {   // stores all ETF values from 1 to N
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

// for any general multiplicative function we can find the values for all the values using seive using


https://codeforces.com/blog/entry/54090









                       





