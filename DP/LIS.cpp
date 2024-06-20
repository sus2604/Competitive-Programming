// RECURSIVE

int solve(vector<int>& arr,int idx,int prev_idx){
    if(idx>=arr.size()) return 0;

    if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx];

    int len=0;

    len=solve(arr,idx+1,prev_idx);
    if(prev_idx==-1 or arr[idx]>arr[prev_idx]){
        len=max(len,1+solve(arr,idx+1,idx));
    }

    return dp[idx][prev_idx+1]=len;
}

// ITERATIVE

vector<int> dp(n,1);
int maxi=1;

for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(arr[i]>arr[j]){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
    maxi=max(maxi,dp[i]);
}

cout<<maxi<<endl;

// print iterative

vector<int> dp(n,1);
vector<int> hash(n);
int maxi=1;
int last_idx=0;

for(int i=1;i<n;i++){
    hash[i]=i;
    for(int j=0;j<i;j++){
        if(arr[i]>arr[j] and dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            hash[i]=j;
        }
    }
    if(maxi>dp[i]){
        maxi=dp[i];
        last_idx=i;
    }
}

vector<int> lis;
lis.push_back(arr[last_idx]);

while(hash[last_idx]!=last_idx){
    last_idx=hash[last_idx];
    lis.push_back(arr[last_idx]);
}

reverse(lis.begin(),lis.end());

return lis;


// NLOGN

// what we are storing is for every length the best ending point to achieve that length in the lis array

// if len is same we compare on last element
// if last element is same we compare based on length


vector<int> lis;

for(int i=0;i<n;i++){
    if(lis.empty() or lis.back()<arr[i]){
        lis.push_back(arr[i]);
    }
    else{
        auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
        *it=arr[i];
    }
}

cout<<lis.size()<<endl;


// printing the LIS

vector<int> lis;
vector<int> insertedAt(n);   // stores the length at whish this element was inserted in the array

for(int i=0;i<n;i++){
    if(lis.empty() or lis.back()<arr[i]){
        lis.push_back(arr[i]);
        insertedAt[i]=lis.size();
    }
    else{
        auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
        *it=arr[i];
        insertedAt[i]=it-lis.begin()+1;
    }
}

int len=lis.size();
vector<int> ans;

for(int i=n-1;i>=0;i--){
    if(insertedAt[i]==len){
        len--;
        ans.push_back(arr[i]);
    }
}

reverse(ans.begin(),ans.end());

// ans in the LIS




