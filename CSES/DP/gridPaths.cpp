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


    vector<vector<char>> grid(n,vector<char>(n));
    // * -> trap
    // . -> free

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    if(grid[0][0]=='*' or grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }


    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[n-1][n-1]=1;

    for(int i=n-2;i>=0;i--){
        if(grid[n-1][i]=='*'){
            dp[n-1][i]=0;
            break;
        }
        else dp[n-1][i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(grid[i][n-1]=='*'){
            dp[i][n-1]=0;
            break;
        }
        else dp[i][n-1]=1;
    }


    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(grid[i][j]=='.'){
                dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
            }
        }
    }
    cout<<dp[0][0]<<endl;



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