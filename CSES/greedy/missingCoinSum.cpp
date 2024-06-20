#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    ll pre=0;
    bool check=false;
    ll ans;
    for(int i=0;i<n;i++){
        if(arr[i]-pre>1){
            ans=pre+1;
            check=true;
            break;
        }
        pre+=arr[i];
    }
    if(!check) ans=pre+1;

    cout<<ans<<endl;

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