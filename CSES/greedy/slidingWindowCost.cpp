#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;
template <typename T>
void print(const vector<T>& a){
  for (const auto& x : a) cout << x << " ";
  cout << endl;
}

class M{
public:
    multiset<int> left;
    multiset<int> right;
    ll left_sum;
    ll right_sum;

    M(){
        left_sum=0;
        right_sum=0;
        left.clear();
        right.clear();
    }


    void balance(){
        if(left.size()-right.size()==2){
            auto it=left.rbegin();
            right.insert(*it);
            right_sum+=*it;
            left_sum-=*it;
            left.erase(left.find(*it));
        }
        else if(right.size()-left.size()==2){
            auto it=right.begin();
            left.insert(*it);
            left_sum+=*it;
            right_sum-=*it;
            right.erase(it);
        }
    }

    void add(int x){
        if(!right.empty() and x>*right.begin()){
            right.insert(x);
            right_sum+=x;
        }
        else{
            left.insert(x);
            left_sum+=x;
        }

        balance();
    }

    void remove(int x){
        auto left_find=left.find(x);
        auto right_find=right.find(x);

        if(left_find!=left.end()){
            left_sum-=*left_find;
            left.erase(left_find);
        }
        else{
            right_sum-=*right_find;
            right.erase(right_find);
        }

        balance();
    }

    ll median(){
        if(left.size()>=right.size()){
            ll mid=*left.rbegin();
            return mid*1LL*left.size()-left_sum+right_sum-mid*1LL*right.size();
        }
        else{
            int mid=*right.begin();
            return mid*1LL*left.size()-left_sum+right_sum-mid*1LL*right.size();
        }
    }
};

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    M mid;

    for(int i=0;i<k;i++){
        mid.add(a[i]);
    }

    cout<<mid.median()<<" ";

    for(int i=k;i<n;i++){
        mid.remove(a[i-k]);
        mid.add(a[i]);
        cout<<mid.median()<<" ";
    }
    cout<<endl;


}

int main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;

    while(t--){
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << elapsed.count() * 1e-9<<" seconds" ;
    return 0;
}

// Don't make it complex, make it simple
// Look for extremities
// Generalize the approach
// Reverse Engineering
// Elimination
// Imaginative
// Think Opposite
// Diagram
// Observation