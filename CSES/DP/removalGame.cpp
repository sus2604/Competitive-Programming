#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int k=0;k<n;k++){
        for(int i=0,j=k+i;i<n and j<n;i++,j++){
            if(i==j) dp[i][j]=arr[i];
            else if(j==i+1) dp[i][j]=max(arr[i],arr[j]);
            else dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

    cout<<dp[0][n-1]<<endl;

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