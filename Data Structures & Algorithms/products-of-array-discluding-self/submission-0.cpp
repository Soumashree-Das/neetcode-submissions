class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int j = 0;
        vector<int> products;
        int product;
        for(int i = 0 ; i < nums.size() ; i++){
            product = 1;
            j=0;
            while(j<nums.size()){
                if(j!=i)
                    product*=nums[j];
                j++;
            }
            products.push_back(product);
        }
        return products;
    }
};
