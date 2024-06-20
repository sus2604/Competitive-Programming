// prefix function

-> for a string s of length n, LPS[i] is the length of the longest proper prefix of the substring s[0....i], which is also a suffix of this substring. a proper prefix of a string is a prefix that is not equal to the string itself.

LPS[0]=0;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// to do pattern matching in this we create p + "#" + t and find the kmp array for this string and search the length of p in the array

