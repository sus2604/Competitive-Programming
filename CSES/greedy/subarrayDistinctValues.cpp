#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;
template <typename T>
void print(const vector<T>& a){
  for (const auto& x : a) cout << x << " ";
  cout << endl;
}

void solve(){
    int n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    map<ll,ll> mp;
    ll cnt=0;
    int j=0;

    for(int i=0;i<n;i++){
        mp[a[i]]++;

        while(mp.size()>k){
            mp[a[j]]--;
            if(mp[a[j]]==0){
                mp.erase(a[j]);
            }
            j++;
        }
        cnt+=(i-j+1);
    }

    cout<<cnt<<endl;


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