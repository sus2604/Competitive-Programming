// Z function

Z[i] is the length of the longest string that is at the same time a prefix of s and prefix of substring starting at i  s[0...x-1]=s[i...i+x-1]

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


// to do pattern matching in this we create p + "#" + t and find the Z array for this string and search the length of p in the array