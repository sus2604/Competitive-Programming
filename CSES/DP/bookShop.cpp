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
    int n,sum;
    cin>>n>>sum;

    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

    // find max number of pages that can be taken for price<=sum

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=price[i-1]){
                dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][j-price[i-1]]);
            }
        }
    }

    cout<<dp[n][sum]<<endl;


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