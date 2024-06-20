
// look at the first triangle made

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();

        //[a,b,c,d,e,f] -> take base as af
        // abf+ab+bcdef
        // acf+abc+cdef
        // adf+abcd+def
        // aef+fe+abcde

        vector<vector<int>> dp(n,vector<int>(n,1e9));

        for(int m=0;m<n;m++){
            for(int i=0,j=m+i;i<n and j<n;i++,j++){
                if(i==j) dp[i][j]=0;
                else if(i+1==j) dp[i][j]=0;
                else if(i+2==j) dp[i][j]=values[i]*values[i+1]*values[i+2];
                else{
                    for(int k=i+1;k<=j-1;k++){
                        int cost=values[i]*values[k]*values[j];
                        dp[i][j]=min(dp[i][j],cost+dp[i][k]+dp[k][j]);
                    }
                }

            }
        }

        return dp[0][n-1];
    }
};


