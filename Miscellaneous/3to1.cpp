
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
#define int long long
int mod=1e9+7;
void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printString(string& st){
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}
 
class median{
    public:
    multiset<int> left;
    multiset<int> right;
    int sum_l = 0;
    int sum_r = 0;
    
    void balance(){
        if(left.size()-right.size()==2){
            auto it=left.rbegin();
            right.insert(*it);
            sum_r+=*it;
            sum_l-=*it;
            left.erase(left.find(*it));
        }
        else if(right.size()-left.size()==2){
            auto it=right.begin();
            left.insert(*it);
            sum_r-=*it;
            sum_l+=*it;
            right.erase(right.find(*it));
        }
    }
    void addNum(int x) {
        if(!right.empty() and x>*right.begin()){
            right.insert(x);
            sum_r+=x;
        }
        else{
            left.insert(x);
            sum_l+=x;
        }
    
        balance();
    }
    int difference() {
        return sum_r-sum_l;
    }
    int med(){
        
        if(left.size()>right.size()) return *left.rbegin();
        else if(right.size()>left.size()) return *right.begin();
    }
        
};



void solve()
{
    int n,q; 
    cin >> n>>q;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    vector<int> res(n);
    vector<int> mid(n);
    
    median m;

    for(int i=0;i<n;i++){
       m.addNum(arr[i]);
       if(i%2==0){
          mid[i]=m.med();
          //cout<<m.sum_l<<" "<<m.sum_r<<endl;
          res[i]=(m.left.size()>m.right.size())?m.difference()+2*m.med():m.difference();
       }
       
        
    }
    //cout<<endl;
    
    //print(res);

    for(int i=0;i<q;i++){
        int x=queries[i];
        cout<<res[x-1]<<" ";
    }
    cout<<endl;

}
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
  
    int t;
    cin>>t;

    while(t--){
        solve();
    }
  
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << elapsed.count() * 1e-9 ;
    
  return 0;
}

