class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s:strs){
            string t=s;
            sort(t.begin(),t.end());
            if(mp.find(t)==mp.end())mp.insert({t,{s}});
            else mp[t].push_back(s);
        }
        vector<vector<string>> vec;
        for(auto it:mp){
            vec.push_back(it.second);
        }
        return vec;
    }
};
