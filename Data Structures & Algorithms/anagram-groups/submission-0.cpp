class Solution {
public:
    bool isAnagram(string s1,string s2){
        if(s1.size()!=s2.size())return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        
        vector<bool> visited(strs.size() , false);

        for(int i=0 ; i < strs.size() ; i++){
            if(visited[i])continue;

            vector<string> group = {strs[i]};
            visited[i] = true;
            
            for(int j = i + 1 ; j < strs.size() ; j++){
                if(isAnagram(strs[i],strs[j])){
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            anagrams.push_back(group);
        }
        return anagrams;
    }
};
