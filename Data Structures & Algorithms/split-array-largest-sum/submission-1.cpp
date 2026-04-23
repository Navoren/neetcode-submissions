class Solution {

private:
    bool canSplit(vector<int>& nums, int k, int maxSum){
        int subArr = 1, currSum = 0;
        for(int num : nums){
            currSum += num;
            if(currSum > maxSum){
                subArr++;
                if(subArr > k) return false;
                currSum = num;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(canSplit(nums, k , mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};