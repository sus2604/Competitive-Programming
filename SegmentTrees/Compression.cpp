void compression(vector<ll>& a){
    vector<ll> b=a;
    int n=a.size();

    sort(b.begin(),b.end());

    int idx=1;

    map<ll,ll> mpp;

    for(int i=0;i<n;i++){
        if(!mpp[b[i]]){
            mpp[b[i]]=idx;
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        a[i]=mpp[a[i]];
    }
    

}