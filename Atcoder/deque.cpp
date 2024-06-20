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

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    ll sum=accumulate(arr.begin(),arr.end(),0LL);

    for(int k=0;k<n;k++){
        for(int i=0,j=k+i;i<n and j<n;i++,j++){
            if(i==j) dp[i][j]=arr[i];
            else if(i+1==j) dp[i][j]=max(arr[i],arr[j]);
            else{
                dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
    }

    cout<<(2*dp[0][n-1]-sum)<<endl;
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