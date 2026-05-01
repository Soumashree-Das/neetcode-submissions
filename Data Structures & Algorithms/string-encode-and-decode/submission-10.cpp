class Solution {
public:

    string encode(vector<string>& strs) 
    {
        if(strs.empty())return "";
        
        string str;
        str="";
        
        for(auto s:strs){
            str+=(to_string(s.size()))+',';
        }
        str += "#";
        for(string& s:strs){
            str+=s;
        }
        return str;
    }

    // vector<string> decode(string s) 
    // {
    //     vector<string> decoded;
    //     vector<int> sizes;
    //     int i = 0 ;
        
    //     while(s[i]!='#'){
    //         string size = "";
    //         while(s[i]!=',')
    //         {
    //             size+=s[i];
    //             i++;
    //         }
    //         sizes.push_back(stoi(size));
    //         i++;
    //     }
    //     i++;
    //     for(int sz:sizes){
    //         decoded.push_back(s.substr(i,sz));
    //         i+=sz;
    //     }
    //     return decoded;
    // }
    vector<string> decode(string s) 
{
    if(s.empty()){
        return {};
    }
    vector<string> decoded;
    vector<int> sizes;
    int i = 0;

    // Extract sizes before '#'
    while (s[i] != '#') {  
        string size = "";  // Reset for each number
        while (s[i] != ',') {  
            if (!isdigit(s[i])) { 
                throw invalid_argument("Invalid character in size field"); 
            }
            size += s[i];  
            i++;
        }
        sizes.push_back(stoi(size)); // Convert size to integer
        i++;  // Move past ','
    }
    i++;  // Move past '#'

    // Extract strings using sizes
    for (int sz : sizes) {
        decoded.push_back(s.substr(i, sz)); // Extract substring of length sz
        i += sz;  
    }

    return decoded;
}

};
