#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// could also use greater<int> (decreasing order)
// for implementing multiset we use less_equal<int>
ordered_set st;
st.insert(2);
st.insert(5);
st.insert(7);
st.insert(6);

// to get the index of element in the set  -> we use find_by_order

cout<<st.find_by_order(0)<<endl;
cout<<st.find_by_order(1)<<endl;
cout<<st.find_by_order(2)<<endl;
cout<<st.find_by_order(3)<<endl;

// to get number of elements strictly smaller than x -> we use order_of_key

cout<<st.order_of_key(6);

// to get lower_bound and and upper_bound is same as sets
// erase is also same


// to get number of elements striclty greater insert negative elements and use the set as usual

return 0;
}