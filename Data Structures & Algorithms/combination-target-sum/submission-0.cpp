class Solution {
public: 

void seq(vector<int>& candidates, int target, int ind, vector<int> &temp, vector<vector<int>> &ans){
    if(ind == candidates.size()){
        if(target == 0)
        ans.push_back(temp);
        return;
    }
    

    if(candidates[ind] <= target){
        temp.push_back(candidates[ind]);
        seq(candidates, target - candidates[ind], ind, temp, ans);
        temp.pop_back();
    }

    seq(candidates, target, ind+1, temp, ans);

}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        seq(candidates, target, 0, temp, ans);
        return ans; 
    }
};