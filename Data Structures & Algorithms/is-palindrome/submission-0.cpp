class Solution {
public:
    string convertToOneWord(string s) {
        string newS;
        
        for (char c : s) {
            if (isalnum(c)) { // Keep only alphanumeric characters
                newS.push_back(tolower(c));
            }
        }
        return newS;
    }

    bool isPalindrome(string s) {
        s = convertToOneWord(s);
        int left = 0, right = s.size() - 1;

        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
