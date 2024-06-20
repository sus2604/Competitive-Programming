class Solution {
public:
    int dp[105][10005];
    int solve(int k,int n){
        if(n==0 or n==1) return 1;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];

        int ans=1e9;
        int s=1;
        int e=n;
        while(s<=e){
            int mid=(s+e)/2;
            int left=solve(k-1,mid-1);
            int right=solve(k,n-mid);
            int temp=1+max(left,right);
            if(left<right){   // as we are finding max
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            ans=min(ans,temp);
        }

        return dp[k][n]=ans;
        
    }
    int superEggDrop(int k, int n) {

        memset(dp,-1,sizeof(dp));

        return solve(k,n);
    }
};