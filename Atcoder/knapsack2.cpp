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
    ll W;
    cin>>n>>W;

    vector<ll> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];

    // dp[i][j] -> min weight to get value as j with first i elements

    int sum=accumulate(val.begin(),val.end(),0);

    vector<ll> dp(sum+1,1e9);

    dp[0]=0;


    for(int i=1;i<=n;i++){
        vector<ll> ndp=dp;
        ndp[0]=0;
        for(int j=1;j<=sum;j++){
            ndp[j]=dp[j];
            if(j>=val[i-1]){
                ndp[j]=min(ndp[j],wt[i-1]+dp[j-val[i-1]]);
            }
        }
        dp=ndp;
    }

    ll ans=0;

    for(int i=sum;i>=0;i--){
        if(dp[i]>0 and dp[i]<=W){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;

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