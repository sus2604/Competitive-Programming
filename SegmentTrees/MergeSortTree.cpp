// answers queries such as number of elements <= >= > < in a range [l,r]

// we are basically just storing sorted array as node

// for getting number of elements >=k in range



class SGTree{
    vector<vector<int>> seg;
public:
    SGTree(int n){   // pass n as 1e5+5
        reg.resize(4*n+1);
    }

    vector<int> Merge (const vector<int>& lft, const vector<int>& rgt) {
        vector<int> result;
        int n1 = lft.size(), n2 = rgt.size();
        int l1 = 0, l2 = 0;
 
        while (l1 < n1 && l2 < n2) {
            if (lft[l1] <= rgt[l2]) {
                result.push_back(lft[l1]);
                l1 ++;
            }
            else {
                result.push_back(rgt[l2]);
                l2 ++;
            }
        }
        while (l1 < n1) result.push_back(lft[l1 ++]);
        while (l2 < n2) result.push_back(rgt[l2 ++]);
 
        return result;
    }

    void build(int idx,int low,int high,const vector<int>& arr){
        if(low==high){
            seg[idx]={arr[low]};
            return;
        }
        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,low,mid,arr);
        seg[idx]=Merge(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int l,int r,int k){
        // no overlap
        if(r<low || l>high) return 0; // change reqd as base condition

        //complete overlap
        if(low>=l && high<=r){
            int idx=upper_bound(seg[i].begin(),seg[i].end(),k)-seg[i].begin();
            return seg[i].size()-idx;
        }

        int mid = (low+high)/2;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return left+right;

    }
};

// for updates on merge sort tree we use ordered_set in node