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
void print(const vector<T>& arr) {
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

void solve(){
    int n;
    cin>>n;
    vector<pi> a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        a[i]={x,y};
    }
    auto cmp = [&](pi a,pi b){
        return a.S<b.S;
    };
    sort(a.begin(),a.end(),cmp);

    int cnt=1;
    int prev=a[0].S;
    for(int i=1;i<n;i++){
        if(a[i].F>=prev){
            prev=a[i].S;
            cnt++;
        }
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