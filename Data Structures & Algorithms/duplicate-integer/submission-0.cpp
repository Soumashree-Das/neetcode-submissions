class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashed;
        for(auto it : nums){
            hashed[it]++;
        }
        for(auto it:nums){
            if (hashed[it]>1)return true;
        }
        return false;
    }
};
