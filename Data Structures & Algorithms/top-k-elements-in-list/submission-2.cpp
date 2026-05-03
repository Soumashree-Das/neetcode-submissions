class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // // bucket sort
        unordered_map<int,int> mp;
        for(auto it:nums){
            if(mp.find(it)==mp.end())mp.insert({it,1});
            else mp[it]++;
        }

        // vector<vector<int>> bucket(nums.size()+1);
        // for(auto it:mp){
            
        //     bucket[it.second].push_back(it.first);
        // }

        // vector<int> res;
        // for(int i = bucket.size()-1;i>=0;i--){
        //     for(auto b:bucket[i]){
        //         res.push_back(b);
        //         k--;
        //         if(k==0) return res;
        //     }
        // }
        // return {};

        map<int,vector<int>> m;
        for(auto it:mp){
            if(m.find(it.second)==m.end())m.insert({it.second,{it.first}});
            else m[it.second].push_back(it.first);
        }

        vector<int> result;
        while(k>0){
            for(auto it=m.rbegin();it!=m.rend();it++){
                for(auto it2:it->second){
                    result.push_back(it2);
                    k--;
                    if(k==0) return result;
                }
            }
        }
        return {};
    }
};
