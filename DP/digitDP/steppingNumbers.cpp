class Solution {
public:
    int dp[120][2][10][2];
    int mod=1e9+7;
    int solve(vector<int>& digits,int pos,int tight,int prev,int lz){
        if(pos==digits.size()){
            return 1;
        }
        if(prev!=-1 and dp[pos][tight][prev][lz]!=-1) return dp[pos][tight][prev][lz];

        int ans=0;
        int ub=(tight)?digits[pos]:9;

        if(lz) ans+=solve(digits,pos+1,0,prev,lz);

        for(int dig=0;dig<=ub;dig++){
            if(lz and dig!=0){
                ans=(ans+solve(digits,pos+1,tight&(dig==ub),dig,lz&(dig==0)))%mod;
            }
            else if(lz==0){
                if(abs(dig-prev)==1){
                    ans=ans+solve(digits,pos+1,tight&(dig==ub),dig,lz&(dig==0))%mod;
                }
            }

        }
        if(prev==-1) return ans%mod;
        return dp[pos][tight][prev][lz]=ans%mod;
    }
    int countSteppingNumbers(string low, string high) {
        vector<int> f,s;
        for(int i=0;i<low.size();i++){
            f.push_back(low[i]-'0');
        }
        for(int i=0;i<high.size();i++){
            s.push_back(high[i]-'0');
        }

        memset(dp,-1,sizeof(dp));
        int ans1=solve(f,0,1,-1,1)%mod;
        memset(dp,-1,sizeof(dp));
        int ans2=solve(s,0,1,-1,1)%mod;

        int ans =  ans2-ans1+mod;

        for(int i=1;i<f.size();i++){
            if(abs(f[i]-f[i-1])!=1){
                return ans%mod;
            }
        }

        return (ans+1)%mod;


    }
};