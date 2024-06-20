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

class Segtree{
public:
    vector<ll> tree;
    Segtree(int n){
        tree.resize(4*n+2);
    }
    ll combine(ll l,ll r){
        return min(l,r);
    }

    void build(int idx,int lo,int hi,vector<ll>& arr){
        if(lo==hi){
            tree[idx]=arr[lo];
            return;
        }
        int mid=(lo+hi)/2;
        build(2*idx+1,lo,mid,arr);
        build(2*idx+2,mid+1,hi,arr);
        tree[idx]=combine(tree[2*idx+1],tree[2*idx+2]);

    }
    ll query(int idx,int lo,int hi,int l,int r){
        if(lo>=l and hi<=r) return tree[idx];
        if(r<lo or l>hi) return 1e18;

        int mid=(lo+hi)/2;
        ll left=query(2*idx+1,lo,mid,l,r);
        ll right=query(2*idx+2,mid+1,hi,l,r);

        return combine(left,right);
    }
};

void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<ll> pre(n);
    pre[0]=arr[0];

    for(int i=1;i<n;i++) pre[i]=pre[i-1]+arr[i];

    Segtree st(n);

    st.build(0,0,n-1,pre);

    ll ans=pre[a-1];
    for(int i=a;i<n;i++){
        int l=max(i-b,0);
        int r=i-a;

        if(i<b) ans=max(ans,pre[i]);
        ll neg=st.query(0,0,n-1,l,r);
        ans=max(ans,pre[i]-neg);
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