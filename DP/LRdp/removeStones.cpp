class Solution {
public:
    #define F first
    #define S second
    int dp[105][105][105];
    vector<int> rod_cut;
    int solve(int l,int r,int extra,vector<pair<int,int>>& groups){
        if(l>r) return 0;
        if(dp[l][r][extra]!=-1) return dp[l][r][extra];

        int ans=solve(l+1,r,0,groups)+rod_cut[extra+groups[l].S];
        for(int i=l+2;i<=r;i++){
            if(groups[i].F==groups[l].F){
                ans=max(ans,solve(l+1,i-1,0,groups)+solve(i,r,groups[l].S+extra,groups));
            }
        }

        return dp[l][r][extra]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        rod_cut.resize(n+1);
        rod_cut[0]=0;
        for(int i=1;i<=n;i++){
            for(int cut=1;cut<=i;cut++){
                rod_cut[i]=cut*cut+rod_cut[i-cut];
            }
        }


        vector<pair<int,int>> groups;
        for(int i=0;i<n;i++){
            int size=1;
            int val=boxes[i];
            while(i+1<n and boxes[i]==boxes[i+1]){
                size++;
                i++;
            }
            groups.push_back({val,size});
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,groups.size()-1,0,groups);
        
    }
};

// claim -> to get max profit -> either remove whole group or wait for it to combine with other

// to delete whole cost is the rod cutting problem