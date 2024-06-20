// creating subsets

// template

int dp[1<<20];    // arr ->precomputed array for every mask possible before hand

int solve(int mask){            // mask = (1<<N)-1
    if(mask==0) return 0;

    if(dp[mask]!=-1) return dp[mask];
    int ans=0;

    for(int submask=mask;submask;submask=(submask-1)&mask){
        int cost = arr[submask];
        ans=max(ans,cost+solve(mask^submask));
    }

    return dp[mask]=ans;
}

// cses elevator rides, divide into k subsets of equal sums, fair distribution of cookies, minimum-number-of-work-sessions-to-finish-the-tasks


elevator / session time 



class Solution {
public:
    int solve(vector<int>& dp,int sessionTime,int mask,vector<int>& total){
        if(mask==0) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int ans=INT_MAX;
        for(int sb=mask;sb>0;sb=(sb-1)&mask){
            int complement = mask-sb;
            if(total[sb]<=sessionTime){
                ans=min(ans,1+solve(dp,sessionTime,complement,total));
            }
        }
        return dp[mask]=ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();

        vector<int> total(1<<n,0);

        for(int mask=0;mask<(1<<n);mask++){
            int sum=0;
            for(int bit=0;bit<n;bit++){
                if(mask&(1<<bit)) sum+=tasks[bit];
            }
            total[mask]=sum;
        }

        vector<int> dp(1<<16,-1);
        return solve(dp,sessionTime,(1<<n)-1,total);


    }
};