// subset dp
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


vector<ll> pair_cost;
ll dp[1<<17];
int N;

ll max_score(int mask){
    if(mask==0){
        return 0;
    }
    if(dp[mask]!=-1) return dp[mask];

    ll score=-1e18;

    for(int submask=mask;submask;submask=(submask-1)&mask){
        score=max(score,pair_cost[submask]+max_score(submask^mask));
    }

    return dp[mask]=score;
}



void solve(){
    int n;
    cin>>n;
    N=n;

    vector<vector<ll>> cost(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }

    pair_cost.resize(1<<n,0);

    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int j=i+1;j<n;j++){
                    if(mask&(1<<j)) pair_cost[mask]+=cost[i][j]; 
                }
            }
            
        }
    }

    memset(dp,-1,sizeof(dp));

    cout<<max_score((1<<n)-1)<<endl;

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