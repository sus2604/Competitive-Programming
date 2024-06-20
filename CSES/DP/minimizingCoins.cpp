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
void printString(string& st){
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}


void solve(){
    int n,sum;
    cin>>n>>sum;

    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    // make sum with minimum number of coins

    vector<vector<int>> dp(n+1,vector<int>(sum+1,1e9));

    for(int i=0;i<=sum;i++){
        dp[0][i]=1e9;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=coins[i-1]){
                dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
            }
        }
    }

    int ans=dp[n][sum];
    if(ans==1e9) ans=-1;

    cout<<ans<<endl;

    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;

    while(t--){
        solve();
    }

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