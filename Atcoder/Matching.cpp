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

vector<vector<int>> v;

int dp[1<<22];

void solve(){
    int n;
    cin>>n;

    vector<vector<int>> comp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>comp[i][j];
        }
    }
    

    memset(dp,-1,sizeof(dp));

    function<int(int)> ways=[&](int mask){
        int idx=__builtin_popcount(mask);
        if(idx>=n){
            return 1;
        }
        if(dp[mask]!=-1) return dp[mask];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(comp[idx][i]==0) continue;
            if(mask&(1<<i)) continue;
            cnt=(cnt+ways(mask|(1<<i)))%mod;
        }

        return dp[mask]=cnt%mod;
    };

    cout<<ways(0)<<endl;
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