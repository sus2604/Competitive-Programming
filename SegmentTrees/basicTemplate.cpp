class SGTree{
    vector<int> seg;   // node is an integer  can be made anything
public:
    SGTree(int n){   // pass n as 1e5+5
        seg.resize(4*n+5);
    }

    int combine(int l,int r){
        return min(l,r);
    }

    void build(int idx,int low,int high,vector<int>& arr){
        if(low==high){
            seg[idx]=arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=combine(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int l,int r){
        // no overlap
        if(r<low || l>high) return INT_MAX; // change reqd as base condition

        //complete overlap
        if(low>=l && high<=r) return seg[idx];

        int mid = (low+high)/2;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return combine(left,right);

    }

    void update(int idx,int low,int high,int i,int val){
        if(low==high){
            seg[idx]=val;   // if increment seg[idx]+=val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);

        seg[idx]=combine(seg[2*idx+1],seg[2*idx+2]);

    }  
};
