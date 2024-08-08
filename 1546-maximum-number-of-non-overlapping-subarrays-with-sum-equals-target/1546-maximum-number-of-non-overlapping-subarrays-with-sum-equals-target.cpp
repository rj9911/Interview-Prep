class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];  // summing up the current element
            if(mp.find(sum - target )!= mp.end()){ // if target sum is Found
                ans+= 1; //increament the result
                mp.clear(); 
                sum = 0; //make current sum = 0;
            }
            else if(sum == target){ //if sum is equal to target
                sum = 0; 
                ans+= 1;
                mp.clear();
            }
            else{
                mp[sum]++; // else store the sum
            }
        }
        return ans;
    }

};