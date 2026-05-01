class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indices;

        // //we first hash all indices to the value in the hashmap indices.
        // for(int i = 0; i < nums.size() ; i++){
        //     indices[nums[i]] = i;
        // }

        // //while visiting every element in the array we first check if its diff exist in the hash mao ir not . if yes we return the two indices because it is already known that only one solution exists.
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(indices.count(target-nums[i]) && indices[target-nums[i]] != i){
        //         return {i,indices[target-nums[i]]};
        //     }
        // }

        for(int i = 0; i < nums.size() ; i++){
            int complement = target - nums[i];
            if(indices.count(complement)){
                return {indices[complement],i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
