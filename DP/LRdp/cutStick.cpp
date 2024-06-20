
// looking at where the first cut in made

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int N=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(N,vector<int>(N,1e9));

        for(int k=0;k<N;k++){
            for(int i=0,j=k+i;i<N and j<N;i++,j++){
                for(int m=i;m<=j;m++){
                    int left=(m==i)?0:dp[i][m-1];
                    int right=(m==j)?0:dp[m+1][j];
                    int cost=((j==N-1)?n:cuts[j+1])-((i==0)?0:cuts[i-1]);
                    dp[i][j]=min(dp[i][j],left+right+cost);
                }
            }
        }
        return dp[0][N-1];
    }
};