#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;
void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int dp[100005][2][105];

void solve(){
    string k;
    cin>>k;
    int d;cin>>d;

    memset(dp,-1,sizeof(dp));
    int n=k.size();

    vector<int> digits;  // generate this with input

    for(int i=0;i<n;i++){
        digits.push_back(k[i]-'0');
    }
    
    
    function<int(int,int,int)> sum_digits=[&](int pos,int tight,int sum){
        if(pos>=n){
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];

        int ub=(tight)?digits[pos]:9;
        int ans=0;

        for(int dig=0;dig<=ub;dig++){
            ans=(ans+sum_digits(pos+1,tight&(dig==ub),(sum+dig)%d))%mod;
        }

        return dp[pos][tight][sum]=ans;
    };

    cout<<(sum_digits(0,1,0)-1+mod)%mod<<endl;
}

int main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;

    while(t--){
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << elapsed.count() * 1e-9<<" seconds" ;
    return 0;
}

// Don't make it complex, make it simple
// Look for extremities
// Generalize the approach
// Reverse Engineering
// Elimination
// Imaginative
// Think Opposite
// Diagram
// Observation