#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;

int dp[100005][105];

int solve(vector<int>& arr,int prev,int idx,int m){
    if(idx>=arr.size()) return 1;

    if(dp[idx][prev]!=-1) return dp[idx][prev];

    int ans=0;

    if(arr[idx]==0){
        ans=(ans+solve(arr,prev,idx+1,m))%mod;
        if(prev!=1) ans=(ans+solve(arr,prev-1,idx+1,m))%mod;
        if(prev!=m) ans=(ans+solve(arr,prev+1,idx+1,m))%mod;
    }
    else{
        if(abs(prev-arr[idx])<=1) ans=(ans+solve(arr,arr[idx],idx+1,m))%mod;
    }

    return dp[idx][prev]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<100005;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=-1;
        }
    }

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=0;

    if(arr[0]==0){
        for(int i=1;i<=m;i++){
            ans=(ans+solve(arr,i,1,m))%mod;
        }
    }
    else ans=solve(arr,arr[0],1,m);

    cout<<ans<<endl;


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