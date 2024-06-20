// subsequence and substring

// find number of strings of size n such that "0100" is not a subsequence


int solve(int idx,int match){
    if(match==4) return 0;
    if(idx==n) return 1;

    if(dp[idx][match]!=-1) return dp[idx][match];

    int ans=solve(idx+1,match)+solve(idx+1,match+1);

    return dp[idx][match]=ans;
}

// find number of strings of size n such that "0100" is not a substring

using bitmask to maintain the prefix of the string already used 

int dp[100010][16];


int solve(int idx,int match){
    if(idx==n) return 1;

    if(dp[idx][match]!=-1) return dp[idx][match];

    int ans=0;

    if(idx>=3 and match==2){
        // don't allow
        ans=solve(idx+1,5)  // 101  added one and maintained prefix of length 3
    }
    else{
        // allow zero
        ans=solve(idx+1,((match<<1)|0)&7);
        // allow one
        ans+=solve(idx+1,((match<<1)|1)&7)
    }
}

// can also be done using creating a finite state machine