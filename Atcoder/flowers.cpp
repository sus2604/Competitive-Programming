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
class SegTree{
public:
    vector<ll> tree;
    SegTree(int n){
        tree.resize(4*n+5,0);
    }
    ll combine(ll l,ll r){
        return max(l,r);
    }
    void update(int idx,int low,int high,int i,ll val){
        if(low==high){
            tree[idx]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);

        tree[idx]=combine(tree[2*idx+1],tree[2*idx+2]);
    }
    ll query(int idx,int low,int high,int l,int r){
        if(low>=l && high<=r) return tree[idx];

        if(low>r || high<l) return -1e18;

        int mid=(low+high)/2;
        ll left=query(2*idx+1,low,mid,l,r);
        ll right=query(2*idx+2,mid+1,high,l,r);

        return combine(left,right);
    }
};

void solve(){
    int n;
    cin>>n;

    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];

    vector<ll> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];

    int N=2e5+5;

    SegTree st(N);

    vector<ll> dp(n);

    for(int i=0;i<n;i++){
        dp[i]=cost[i];
        ll ans=st.query(0,0,N-1,0,h[i]-1);
        if(ans!=-1e18) dp[i]+=ans;
        st.update(0,0,N-1,h[i],dp[i]);
    }

    ll ans=*max_element(dp.begin(),dp.end());
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