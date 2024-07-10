class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>anomaly(nums.size(), 0);
        vector<bool>result;

        // pointing out wherever array might voilate special array policy
        for(int i=1; i<nums.size(); i++){
            if((nums[i-1]%2 == 0 && nums[i]%2 == 0) || (nums[i-1]%2 !=0 && nums[i]%2 != 0))
                anomaly[i] = 1;
        }

        // summing up anomaly array to make prefix sum array.
        int prefix = 0;
        for(int i=0; i<anomaly.size(); i++){
            prefix += anomaly[i];
            anomaly[i] = prefix;
        }

        // now we just have to check if in queries if values in prefix array is equal or not
        // if values are equal then range is valid else invalid.
        for(auto i: queries){
            if(anomaly[i[0]] == anomaly[i[1]])
                result.push_back(true);
            else
                result.push_back(false);
        }

        return result;
    }

};