// take each node as root and calculate

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        vector<int> prefix(n);
        prefix[0]=freq[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+freq[i];
        }
        for(int k=0;k<n;k++){
            for(int i=0,j=k+i;i<n and j<n;i++,j++){
                if(j==i){
                    dp[i][j]=freq[i];
                }
                else if(j==i+1){
                    dp[i][j]=min(freq[i]+2*freq[j],2*freq[i]+freq[j]);
                }
                else{
                    int sum=prefix[j]-((i==0)?0:prefix[i-1]);
                    for(int m=i;m<=j;m++){
                        int left=(m==i)?0:dp[i][m-1];
                        int right=(m==j)?0:dp[m+1][j];
                        dp[i][j]=min(dp[i][j],left+right+sum);
                    }
                    
                }
            }
        }
        return dp[0][n-1];
    }
};