// LC : 1000

class Solution {
public:
    int dp[55][55];

    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();

        if((n-1)%(k-1)!=0) return -1;

        vector<int> pre(n);
        pre[0]=stones[0];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+stones[i];
        }

        memset(dp,-1,sizeof(dp));

        function<int(int,int)> solve=[&](int l,int r){
            if(r-l+1<=k-1) return 0;    // if less than reqd

            if(dp[l][r]!=-1) return dp[l][r];
            int ans=1e9;

            for(int i=l;i<r;i+=k-1){
                ans=min(ans,solve(l,i)+solve(i+1,r));  // gives 1 and k-1
            }
            if((r-l)%(k-1)==0) ans+=pre[r]-((l==0)?0:pre[l-1]);

            return dp[l][r]=ans;
            
        };

        return solve(0,n-1);
    }
};