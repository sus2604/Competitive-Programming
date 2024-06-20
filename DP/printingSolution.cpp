// printing solution form dp is done by two ways
-> rechecking solution 
-> reconstructing solution using back pointers



-> Rechecking solution

// 1) printing subset sum = k

bool solve(vector<int>& arr,int idx,int left){
    if(left==0) return true;

    if(idx>=arr.size()) return false;

    if(dp[idx][left]!=-1) return dp[idx][left];

    bool ans = solve(arr,idx+1,left) || solve(arr,idx+1,left-arr[idx]);

    return dp[idx][left]=ans;
}

void print(vector<int>& arr,int idx,int left){           
    if(idx>=arr.size()){
        return;
    }

    if(solve(arr,idx+1,left)){
        print(arr,idx+1,left);
    }
    else if(solve(arr,idx+1,left-arr[idx])){
        cout<<arr[idx]<<" ";
        print(arr,idx+1,left-arr[idx]);
    }
}

// 2) printing LIS of the array 

int dp[2000][2000];
int LIS(vector<int>& arr,int idx,int prev_idx){
    int n=arr.size();
    if(idx >= n){
        return 0;
    }
    if(prev_idx != -1 && dp[idx][prev_idx] != -1) return dp[idx][prev_idx];
    
    int ans = LIS(arr, idx + 1, prev_idx); // not take
    
    if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
        ans = max(ans, 1 + LIS(arr, idx + 1, idx)); // take
    }
    
    if(prev_idx == -1) return ans;
    
    return dp[idx][prev_idx] = ans;
}

void printLIS(vector<int>& arr, int idx, int prev_idx) {
    if(idx >= arr.size()) return;
    
    int take = -1e9;
    if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
        take = 1 + LIS(arr, idx + 1, idx);
    }
    
    int not_take = LIS(arr, idx + 1, prev_idx);
    
    if(take > not_take) {
        cout << arr[idx] << " ";
        printLIS(arr, idx + 1, idx);
    } else {
        printLIS(arr, idx + 1, prev_idx);
    }
}

// If take is greater than not_take, it means the LIS that includes the current element is longer. So, we print the current element and recursively call printLIS for the next index, updating prev_idx to the current index.

// 3) printing LCS of the strings

int LCS(string &s1, string &s2, int i, int j) {
    if (i == s1.size() || j == s2.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans=-1e9

    if (s1[i] == s2[j]) {
        ans = 1 + LCS(s1, s2, i + 1, j + 1);
    } else {
        ans= = max({ans,LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1)});
    }

    return ans;
}

void printLCS(string &s1, string &s2, int i, int j) {
    if (i == s1.size() || j == s2.size()) {
        return;
    }

    if (s1[i] == s2[j]) {
        cout << s1[i];
        printLCS(s1, s2, i + 1, j + 1);
    } else {
        if (LCS(s1,s2,i+1,j) > LCS(s1,s2,i,j+1)) {
            printLCS(s1, s2, i + 1, j);
        } else {
            printLCS(s1, s2, i, j + 1);
        }
    }
}

// 4) printing TSP path using rechecking

int dp[20][1<<20]

int solve(int city,int mask,int start){
    if(mask==(1<<N)-1){
        return dis[city][start];
    }

    if(dp[city][mask]!=-1) return dp[city][mask];

    int ans=1e9;

    for(int i=0;i<N;i++){
        if(mask&(1<<i)) continue;
        ans=min(ans,dis[city][i]+solve(i,mask|(1<<i),start));
    }

    return dp[city][mask]=ans;
}

void print(int mask,int city){
    if(mask==(1<<n)-1){
        cout<<0<<" ";
        return;
    }

    int ans=1e9;
    int next=-1;

    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        int new_ans=dist[city][i]+tsp(mask|(1<<i),i);
        if(ans>new_ans){
            ans=new_ans;
            next=i;
        }
    }
    cout<<next<<" ";
    print(mask|(1<<next),next);
}

-> reconstruct solution

// 1) subset sum

   bool solve(vector<int>& arr, int idx, int sum) {
    if (sum == 0) return true;
    if (idx >= arr.size()) return false;

    if (dp[idx][sum] != -1) return dp[idx][sum];

    bool not_take = solve(arr, idx + 1, sum);
    bool take = false;

    if (arr[idx] <= sum) {
        take = solve(arr, idx + 1, sum - arr[idx]);
    }
    if (take) {
        parent[idx][sum] = idx + 1; // store the next index if we take the current element
    } 

    return dp[idx][sum] = take || not_take;
}

    int sum = target_sum;
    int idx = 0;

    // Finding the first index that is part of the subset
    while (idx < n && parent[idx][sum] == -1) {
        idx++;
    }

    while (idx < n && sum > 0) {
        if (parent[idx][sum] != -1) {
            cout << arr[idx] << " ";
            sum -= arr[idx];
            idx = parent[idx][sum];
        }
        else idx++;
    }

// 2) LIS
     
     int solve(vector<int>& arr, int idx, int prev_idx) {
    
        if (idx >= arr.size()) return 0;

        if (dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];

        int ans=-1e9;
        
        ans=solve(arr,idx+1,prev_idx);
        if(prev_idx==-1 or arr[idx]>arr[prev_idx]){
            int new_ans=1+solve(arr,idx+1,idx);
            if(new_ans>ans){
                ans=new_ans;
                parent[idx][prev_idx+1]=idx+1;
            }
        }
        
        return dp[idx][prev_idx+1] = ans;
    }

    int idx = 0;
    int prev_idx=-1;

    // Finding the first index that is part of the subset
    while (idx < n && parent[idx][prev_idx+1] == -1) {
        idx++;
    }

    while (idx < n and idx!=-1) {
        if (parent[idx][prev_idx+1] != -1) {
            cout << arr[idx] << " ";
            int next_idx = parent[idx][prev_idx+1];
            prev_idx=idx;
            idx=next_idx;
        }
        else idx++;
    }


// 3) LCS

// can be done in similar way

// 4) TSP

    int tsp(int mask, int pos) {
        if (mask == (1 << n) - 1) {
            return dist[pos][0]; // Return to the starting city
        }

        if (dp[mask][pos] != -1) {
            return dp[mask][pos];
        }

        int ans = INF;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
                if (newCost < ans) {
                    ans = newCost;
                    parent[mask][pos] = city; // Record the path
                }
            }
        }

        return dp[mask][pos] = ans;
    }

    int mask=1;
    int node=0;
    node=parent[mask][node];
    
    while(node!=-1){
        cout<<node<<" ";
        mask=mask|(1<<node);
        node=parent[mask][node];
    }
    cout<<0<<" ";
    cout << endl;