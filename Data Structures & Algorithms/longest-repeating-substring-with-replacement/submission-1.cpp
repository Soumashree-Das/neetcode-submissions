class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int max_length = 0;
        while (r < s.size()) {
            if (mp.find(s[r]) != mp.end()) {
                mp[s[r]]++;
            } else {
                mp.insert({s[r], 1});
            }
            int max_freq = 0;
            for (int i = l; i <= r; i++) {
                max_freq = max(max_freq, mp[s[i]]);
            }
            while ((r - l + 1) - max_freq > k) {
                mp[s[l]]--;
                l++;
                // max_freq = 0;
                // for (int i = l; i <= r; i++) {
                //     max_freq = max(max_freq, mp[s[i]]);
                // }
            }
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};
