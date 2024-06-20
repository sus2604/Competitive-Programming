#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;

bool cmp(vector<ll>& a,vector<ll>& b){
    return a[1]<b[1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<vector<ll>> arr;

    for(int i=0;i<n;i++){
        vector<ll> temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        arr.push_back(temp);
    } 

    sort(arr.begin(),arr.end(),cmp);

    vector<ll> dp(n);
    dp[0]=arr[0][2];

    for(int i=1;i<n;i++){
        int l=0;
        int r=i-1;
        int idx=-1;
        int start=arr[i][0];
        while(l<=r){
            int mid=(l+r)/2;
            if(start>arr[mid][1]){
                idx=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(idx==-1) dp[i]=max(dp[i-1],arr[i][2]);
        else dp[i]=max(dp[i-1],arr[i][2]+dp[idx]);
    }

    cout<<dp[n-1]<<endl;

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