const int MAXN=1e5+5;

bool prime[MAXN];
int spf[MAXN];
int lpf[MAXN];

void prime_seive_and_spf(){
    for(int i=1;i<MAXN;i++){
        prime[i]=true;
    }
    prime[1]=false;
    spf[1]=1;

    for(int i=2;i*i<MAXN;i++){
        if(prime[i]){
            for(int j=i*i;j<MAXN;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<MAXN;i++){
        if(prime[i]){
            for(int j=i;j<MAXN;j+=i){
                if(spf[j]==0) spf[j]=i;
                lpf[j]=i;
            }
        }
    }
}


// prime factorization in logN using spf value

vector<int> prime_factors;
while(num>1){
    int factor = spf[num];
    while(num%factor==0){
        num/=factor;
        prime_factors.push_back(factor);
    }
}

// prime factorization in sqrt(N)

vector<int> prime_factors;

for(int i=2;i*i<=num;i++){
    while(num%i==0){
        num/=i;
        prime_factors.push_back(i);
    }
}
if(num>1) prime_factors.push_back(num);



