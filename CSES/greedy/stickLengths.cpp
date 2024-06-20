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

// 0 1 2 3 4 5   6/2=3   

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    int mid=0;

    if(n%2==0){
        mid=n/2-1;
    }
    else{
        mid=n/2;
    }

    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(a[i]-a[mid]);
    }
    cout<<sum<<endl;
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