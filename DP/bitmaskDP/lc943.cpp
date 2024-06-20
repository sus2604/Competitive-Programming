Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.


// similar to tsp


class Solution {
public:
    vector<vector<int>> dis,dp;
    int calc(string& a,string& b){
        int n=a.size(), m=b.size(), len=1, idx=0;
        while(len<=min(n, m))
        {
            if(a.substr(n-len)==b.substr(0, len))
            {
                idx=len;
            }
            len++;
        }
        string res=b.substr(idx);
        return res.size();
    }
    int solve(int mask,int prev,int n){
        if(mask==((1<<n)-1)) return 0;

        if(dp[mask][prev]!=-1) return dp[mask][prev];
        
        int ans=1e9;

        for(int curr=0;curr<n;curr++){
            if(mask&(1<<curr)) continue;
            ans=min(ans,dis[prev][curr]+solve(mask|(1<<curr),curr,n));
        }
        return dp[mask][prev]=ans;
    }
    string shortestSuperstring(vector<string>& words) {
        int n=words.size();
        //if(n==1) return words[0].size();

        dis.resize(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                dis[i][j]=calc(words[i],words[j]);
            }
        }
        dp.resize((1<<n),vector<int>(n,-1));

        int ans=1e9;

        for(int i=0;i<n;i++){
            
            ans=min(ans,(int)words[i].size()+solve(1<<i,i,n));
        }
        cout<<ans;
        return "";

    }
};


