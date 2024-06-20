#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define F first
#define S second

// optimal way is to get the closest one that got free
// min heap doesn't work
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<pi> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].F >> movies[i].S;
    }
 
    // Sort movies by their ending times
    sort(movies.begin(), movies.end(), [](pi a, pi b) {
        return a.S < b.S;
    });
 
    // Multiset to track end times of movies currently being watched by members
    multiset<int> endTimes;
 
    int ans = 0;
 
    for (const auto& movie : movies) {
        int start = movie.F;
        int end = movie.S;
 
        // Check if there is a member who can start watching this movie
        auto it = endTimes.upper_bound(start);
        if (it != endTimes.begin()) {
            --it;
            endTimes.erase(it);
            endTimes.insert(end);
            ans++;
        } else if ((int)endTimes.size() < k) {
            // If there is a free member, assign the current movie to them
            endTimes.insert(end);
            ans++;
        }
    }
 
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
 
    return 0;
}
