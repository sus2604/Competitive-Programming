// look for the last to be burst

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int m=0;m<n;m++){
            for(int i=0,j=m+i;i<n and j<n;i++,j++){
                for(int k=i;k<=j;k++){
                    int left=(k==i)?0:dp[i][k-1];
                    int right=(k==j)?0:dp[k+1][j];

                    int cost=nums[k]*((i==0)?1:nums[i-1])*((j==n-1)?1:nums[j+1]);
                    dp[i][j]=max(dp[i][j],left+right+cost);
                }  
            }
        }
        return dp[0][n-1];

    }
};