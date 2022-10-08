// Computes the radius of the longest palindrome centered at each element in O(n) total.
// Actual palindrome length is `2 * radius[i] + 1`.
template<typename T_string>
vector<int> odd_manacher(const T_string &pattern) {
    int n = int(pattern.size());
    vector<int> radius(n, 0);
    int loc = 0;

    for (int i = 1; i < n; i++) {
        if (i <= loc + radius[loc])
            radius[i] = min(radius[loc - (i - loc)], loc + radius[loc] - i);

        while (i - radius[i] > 0 && i + radius[i] < n - 1 && pattern[i - radius[i] - 1] == pattern[i + radius[i] + 1])
            radius[i]++;

        // Find the location with the furthest-reaching umbrella.
        if (i + radius[i] > loc + radius[loc])
            loc = i;
    }

    return radius;
}

// Returns a vector `lengths` of size `2 * n + 1` where `lengths[i]` indicates a palindrome starting at
// `(i - lengths[i]) / 2` and ending at `(i + lengths[i]) / 2` (exact division).
template<typename T_string>
vector<int> combined_manacher(const T_string &pattern) {
    int n = int(pattern.size());
    T_string extended(2 * n + 1, 0);

    for (int i = 0; i < n; i++)
        extended[2 * i + 1] = pattern[i];

    return odd_manacher(extended);
}

// Returns whether the substring represented by `[start, end)` is a palindrome using the output of `combined_manacher`.
bool is_palindrome(const vector<int> &lengths, int start, int end) {
    return lengths[start + end] >= end - start;
}


void build(string s){
    vector<int> v = combined_manacher(str);
    for(int i = 0; i < s.size(); ++i){
        if(is_palindrome(v, i, s.size())){
            //do whatever
            ;
        }
    }
}