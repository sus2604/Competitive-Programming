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
    int n,m;
    cin>>n>>m;

    vector<int> p(n),mp(m);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<m;i++) cin>>mp[i];

    multiset<int> st(p.begin(),p.end());

    for(int i=0;i<m;i++){
        int x=mp[i];

        auto it=st.lower_bound(x);
        if(*it==x){
            cout<<*it<<endl;
            st.erase(it);
        }
        else{
            if(it==st.begin()){
                cout<<-1<<endl;
            }
            else{
                it--;
                cout<<*it<<endl;
                st.erase(it);
            }
        }
    }

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