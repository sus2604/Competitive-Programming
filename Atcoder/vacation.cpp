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
    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(3));

    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    vector<vector<int>> dp(n,vector<int>(3,0));

    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];

    for(int i=1;i<n;i++){
        dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }

    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;;
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