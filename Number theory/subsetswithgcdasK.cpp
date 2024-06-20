// C++ code for the approach

#include <bits/stdc++.h>
using namespace std;

// Helper function
int solve(vector<int>& arr, int X, int N, int idx, int gcd, vector<vector<int>>& dp) {
	// Base Case: If we have reached the end of the array
	if (idx == N) {
		// If the current GCD is equal to X, return 1
		if (gcd == X)
			return 1;
		return 0;
	}

	// Check if the subproblem is already solved
	if (dp[idx][gcd] != -1)
		return dp[idx][gcd];

	// Exclude the current element
	int ans = solve(arr, X, N, idx + 1, gcd, dp);

	// Include the current element
	ans += solve(arr, X, N, idx + 1, __gcd(gcd, arr[idx]), dp);

	// Memoize the result
	dp[idx][gcd] = ans;

	return ans;
}

// Function to find the total subsequences
// having GCD = X
int totalValidSubsequences(vector<int>& arr, int X, int N) {
	// store maximum element of arr in mx
	int mx = *max_element(arr.begin(), arr.end());

	// Create a dp-table of size (N+1) x (mx+1)
	vector<vector<int>> dp(N + 1, vector<int>(mx + 1, -1));

	// Call the recursive function
	int count = solve(arr, X, N, 0, 0, dp);

	return count;
}

// Driver Code
int main() {
	vector<int> arr = { 6, 4, 30 };
	int X = 2;
	int N = arr.size();

	// Function call
	cout << totalValidSubsequences(arr, X, N);

	return 0;
}

// This code is contributed by Chandramani Kumar
