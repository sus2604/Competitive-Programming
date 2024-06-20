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

void solve(){
    int n;
    cin>>n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<ll>> dp(n,vector<ll>(n,1e18));

    vector<ll> pre_sum(n);
    pre_sum[0]=arr[0];
    for(int i=1;i<n;i++) pre_sum[i]=pre_sum[i-1]+arr[i];

    for(int m=0;m<n;m++){
        for(int i=0,j=m+i;i<n and j<n;i++,j++){
            if(i==j) dp[i][j]=0;
            else if(i+1==j) dp[i][j]=arr[i]+arr[j];
            else{
                for(int k=i;k<j;k++){
                    ll sum=pre_sum[k];
                    if(i>0) sum-=pre_sum[i-1];
                    sum+=pre_sum[j];
                    sum-=pre_sum[k];
                    dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum,dp[i][j]);
                }
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
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