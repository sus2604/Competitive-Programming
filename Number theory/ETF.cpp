// gives number of numbers which are less than or equal to n and are co prime to n

ETF(p) = p-1

ETF(p^k) = p^(k-1)*(p-1)

ETF(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3) ......

where p1,p2,p3... are prime factors of n

ETF is always even except for 1 and 2

ETF(a*b) = ETF(a)*ETF(b)  where gcd(a,b)=1

ll etf(ll num){
    ll count =num;

    for(int i=2;i*i<=num;i++){

        if(num%i==0){
            count=count-count/i;
            while(num%i==0){
                num/=i;
            }
        }
    }
    if(num>1){
        count=count-count/num;
    }

    return count;
}

//ETF(ETF(N)) <= N/2

// if N-> odd ETF(N) -> even and ETF(N)<=N

// if N-> even ETF(N) <= N/2