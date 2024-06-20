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
    
    string s1,s2;
    cin>>s1>>s2;

    int m=s1.size();
    int n=s2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1]+1;
        }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]!=s2[j-1]){
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
            else dp[i][j]=dp[i-1][j-1];
        }
    }
    cout<<dp[m][n]<<endl;
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