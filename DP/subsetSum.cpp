//Standard knapsack with boolean array would be O(N⋅W), too slow.

bool can[MAX_W];
int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		for(int i = W; i >= x; i--) {
			if(can[i-x]) can[i] = true;
		}
	}
	puts(can[W] ? "YES" : "NO");
}
// Instead of using a boolean array, let's use bitsets and binary shifting to get O(N⋅W/32)
// You don't need to know bitsets to see how this would work for W≤32
// and a bitmask unsigned long long can;, and here we just do it for a longer bitmask.

bitset<MAX_W> can;
int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x); // or just: can |= (can << x);
	}
	puts(can[W] ? "YES" : "NO");
}