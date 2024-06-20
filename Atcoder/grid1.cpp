#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;
void print(vector<ll>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    vector<ll> dp(n,0);
    for(int i=n-2;i>=0;i--){
        if(grid[m-1][i]=='.') dp[i]=1;
        else{
            dp[i]=0;
            break;
        }
    }


    for(int i=m-2;i>=0;i--){
        vector<ll> ndp=dp;
        //print(ndp);
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]=='#') ndp[j]=0;
            else{
                if(j==n-1){
                    if(i==m-2) ndp[j]=(grid[i][j]=='.');
                    else ndp[j]=(dp[j]>0) and (grid[i][j]=='.');
                }
                else{
                    ndp[j]=(ndp[j+1]+dp[j])%mod;
                }
            }
            
        }
        dp=ndp;
    }

    cout<<dp[0]%mod<<endl;
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