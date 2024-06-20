#define ll long long

int power_p(int n,int p){  // power of p in n!
    int g=p;
    int ans=0;

    while(g<=n){
        ans+=(n/g);
        g*=p;
    }
    return ans;
}
