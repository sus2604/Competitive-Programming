// Your task is to count the number of integers between a and b where no two adjacent digits are the same.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[20][2][2][10];
ll solve(vector<int>& digits,int pos,int lz,int tight,int prev){
    if(pos==digits.size()){
        return 1;
    }
    if(prev!=-1 and dp[pos][lz][tight][prev]!=-1){
        return dp[pos][lz][tight][prev];         // to avoid segmentation fault
    }

    ll ans=0;
    int ub=(tight)?digits[pos]:9;

    if(lz) ans+=solve(digits,pos+1,1,0,prev);   // lz with putting 0 at current idx

    for(int dig=0;dig<=ub;dig++){
        if(lz and dig!=0){
            ans+=solve(digits,pos+1,lz&(dig==0),tight&(dig==ub),dig);  // first time putting a non zero number
        }
        else if(lz==0){
            if(dig==prev) continue;           // no leading zeros
            ans+=solve(digits,pos+1,lz&(dig==0),tight&(dig==ub),dig);
        }
    }

    if(prev==-1) return ans;
    return dp[pos][lz][tight][prev]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;
    ll temp=a;

    vector<int> digits_l,digits_r;
    a--;

    while(a){
        digits_l.push_back(a%10);
        a/=10;
    }
    while(b){
        digits_r.push_back(b%10);
        b/=10;
    }

    reverse(digits_l.begin(),digits_l.end());
    reverse(digits_r.begin(),digits_r.end());

    memset(dp,-1,sizeof(dp));

    ll ans1=solve(digits_l,0,1,1,-1);

    memset(dp,-1,sizeof(dp));

    ll ans2=solve(digits_r,0,1,1,-1);

    if(temp==a){
        cout<<ans2<<endl;
        return 0;
    }

    cout<<ans2-ans1<<endl;


    return 0;
}