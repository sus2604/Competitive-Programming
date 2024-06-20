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

    vector<int> dp(n+1,0);

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
    }

    cout<<dp[n]%mod<<endl;
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