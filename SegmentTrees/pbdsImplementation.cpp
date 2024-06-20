// design a data structure to add a element, delete a element and finding the kth largest element

1<=n<=1e5
q<=1e5
x<=1e5  // coordinate compression also possible

// for this kth segment tree is used


// for other features such as lower/upper_bound and no of elements <==/>= we use merge sort tree to get the answer


kth segment tree 

// make sum segment tree and do binary search

int func(int idx,int l=0,int r=n-1,int k){  //returns the kth max
    if(l==r) return arr[l];
    int mid=(l+r)/2;
    if(query(l,mid)<=k){
        return func(2*idx+1,l,mid,k);
    }
    else return func(2*idx+2,mid+1,r,k-seg[2*idx+1]);
}





