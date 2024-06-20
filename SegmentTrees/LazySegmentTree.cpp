class ST {
    vector<int seg,lazy;
public:
    ST(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

    void push_down(int idx, int low,int high){
        // update the previous remaining updates
        // and propagate downwards
        if(lazy[idx]!=0){
            seg[idx]+=(high-low+1)*lazy[idx]; 
            // for max or min
            // seg[idx] = lazy[idx];

            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
                // for max or min

                // lazy[2*idx+1]=lazy[idx];
                // lazy[2*idx+2]=lazy[idx];  
            }
            lazy[idx]=0;
        }
    }

    void build(int idx,int low,int high,vector<int>& arr){
        if(high==low){
            arr[idx]=low;
            return;
        }
        int mid=(high+low)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2]; // change if max
    }

    void update(int idx,int low,int high,int l,int r,int val){
        // update the previous remaining updates
        // and propagate downwards
        push_down(idx,low,high);

        // no overlap

        if(high<l or r<low){
            return;
        }

        // complete overlap

        if(low>=l and high<=r){
           lazy[idx]=val;
           push_down(idx,low,high);
           return;
        }

        // no overlap

        int mid = (low+high)/2;
        update(2*idx+1,low,mid,l,r,val);
        update(2*idx+2,mid+1,high,l,r,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    int query(int idx,int low,int high,int l,int r){

        push_down(idx,low,high);

        // no overlap
        if(r<low || l>high) return 0;

        //complete overlap
        if(low>=l && high<=r) return seg[idx];

        int mid = (low+high)/2;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return left+right ;

    }

};