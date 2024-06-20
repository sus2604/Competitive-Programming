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
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<bool> dp(k+1,false);

    dp[0]=false;

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]){
                if(dp[i-a[j]]==false) dp[i]=true;
            }
        }
    }

    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;


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