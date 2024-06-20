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
// CHT or Li chao Tree
void solve(){
    int n;
    cin>>n;
    ll c;
    cin>>c;

    vector<ll> h(n);
    for(int i=0;i<n;i++) cin>>h[i];

    vector<ll> dp(n,0);
    
    

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