class TimeMap {
public:
    TimeMap() {
        
    }
    
    unordered_map<string,vector<pair<int,string>>> mp;
    void set(string key, string value, int timestamp) {
        pair<int,string> tmp = {timestamp,value};
        mp[key].push_back(tmp);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)== mp.end())return "";
        auto &tmp = mp[key];
        int low = 0;
        int high = tmp.size()-1;
        string ans = "";
        while(high>=low){
            int mid = low+(high-low)/2;
            if(timestamp>=tmp[mid].first){
                ans = tmp[mid].second;
                low=mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }

};
