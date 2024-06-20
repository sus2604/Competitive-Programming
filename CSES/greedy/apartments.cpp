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
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    // x-k and x+k

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    

    auto check=[&](int i,int j){
        return (b[j]>=a[i]-k and b[j]<=a[i]+k);
    };
    int cnt=0;
    int j=0;

    for(int i=0;i<n;i++){
        while(j<m){
            if(check(i,j)){
                cnt++;
                j++;
                break;
            }
            else if(b[j]<a[i]-k) j++;
            else if(b[j]>a[i]+k) break;
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