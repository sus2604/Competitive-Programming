#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod=1e9+7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> lis;

    for(int i=0;i<n;i++){
        if(lis.empty() or arr[i]>lis.back()){
            lis.push_back(arr[i]);
        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            *it=arr[i];
        }
    }

    cout<<lis.size()<<endl;

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