#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;

vector<int> calc(int num){
    vector<int> dig;
    while(num){
        int rem=num%10;
        if(rem!=0) dig.push_back(num%10);
        num/=10;
    }
    sort(dig.begin(),dig.end());
    return dig;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> dp(n+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        int num=i;
        vector<int> digits=calc(num);

        for(auto x:digits){
            dp[i]=min(dp[i],1+dp[i-x]);
        }
    }

    cout<<dp[n]<<endl;

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