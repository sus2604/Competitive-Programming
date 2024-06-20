// factors and divisors
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;

// O(sqrt(N))

void factors(int N){
    int factor_cnt=0;
    for(int i=1;i*i<=N;i++){
        if(N%i==0){
            cout<<i<<endl;
            factor_cnt++;
            if(i!=N/i){
                cout<<N/i<<endl;
                factor_cnt++;
            }
        }
    }
}

// count of factors for every number 1->N

int cnt[MAXN]

void fill_divisors_count(){
    for(int i=1;i<MAXN;i++){
        for(int j=i;j<MAXN;j+=i){
            cnt[j]++;
        }
    }
}


// number of divisors of a number can be obtained in logN by finding the prime factorization of the number and using the formula


no of divisors = (a+1)*(b+1)*(c+1) ......