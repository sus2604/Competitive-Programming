// n<=40
// find the  number of subset for which sum=k


vector<int> v1,v2;
for(int i=0;i<n/2;i++){
    v1.push_back(arr[i]);
}
for(int i=n/2;i<n;i++){
    v2.push_back(arr[i]);
}
int n1=n/2,n2=n-n1;

unordered_map<int,int> m;
for(int mask=0;mask<(1<<n1);mask++){
    int sum=0;
    for(int j=0;j<n1;j++){
        if(mask & (1<<j)){
            sum+=v1[j];
        }
    }
    m[sum]++;
}

int ans=0;

for(int mask=0;mask<(1<<n2);mask++){
    int sum=0;
    for(int j=0;j<n2;j++){
        if(mask & (i<<j)){
            sum+=v2[j];
        }
    }
    if(m.count(k-sum)){
        ans+=m[k-sum];
    }
}

return ans;