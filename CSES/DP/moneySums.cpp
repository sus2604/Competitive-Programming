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

    int sum=accumulate(arr.begin(),arr.end(),0);

    bitset<100005> dp;
    dp[0]=1;
    for(int i=0;i<n;i++){
        int x=arr[i];
        dp |= (dp << x);
    }
    vector<int> res;
    int cnt=0;
    for(int i=1;i<=sum;i++){
        if(dp[i]){
            res.push_back(i);
            cnt++;
        }
        
    }
    
    cout<<cnt<<endl;
    for(auto x:res) cout<<x<<" ";
    cout<<endl;

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