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
    ll x;
    cin>>n>>x;

    vector<ll> tasks(n);
    for(int i=0;i<n;i++){
        cin>>tasks[i];
    }

    vector<pair<ll,ll>> dp(1<<21);      // -> {min weight of last ride, min # of rides}
    dp[0]={0,1};

    for(int mask=1;mask<(1<<n);mask++){
        pair<ll,ll> best={1e18,1e18};
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0) continue;
            auto prev=dp[mask^(1<<i)];
            // added to previous group if possible
            if(prev.F+tasks[i]<=x){
                prev.F+=tasks[i];
            }
            else{
                // form new group
                prev.F=tasks[i];
                prev.S+=1;
            }
            best=min(best,prev);
        }
        dp[mask]=best;
    }

    cout<<dp[(1<<n)-1].S<<endl;



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