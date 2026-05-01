class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        for(int i=0;i<piles.size();i++){
            if(piles[i]>=high)
            high = piles[i];
        }
        long long hours;
        int k = 1;
        while(high>=low){
            int mid = (high+low)/2;
            hours = 0;
            for(auto it:piles){
                hours += (it/mid);
                if(it%mid!=0)hours++;
            }
            // mid = int(mid);
            if(hours<=h){
                k=mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return k;
    }
};
