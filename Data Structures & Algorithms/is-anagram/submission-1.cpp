class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s){
            if(mp.find(it)==mp.end())mp[it]=1;
            else mp[it]++;
        }
        int c=mp.size();
        for(auto it:t){
            if(mp.find(it)==mp.end())return false;
            mp[it]--;
            
        }
        for(auto it:mp){
            if(it.second==0)c--;
        }
        if(c==0)return true;
        return false;
    }
};
