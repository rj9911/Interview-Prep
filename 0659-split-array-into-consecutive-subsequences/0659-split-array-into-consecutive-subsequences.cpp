class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> arr;
        arr.push_back({nums[0], 1});
        for(int i = 1; i<nums.size(); i++){
            int j = arr.size()-1;
            while(j>=0 && nums[i] <=arr[j].first){
                j--;
            }
            if(j == -1){
                arr.push_back({nums[i], 1}); // if no element is less than current number
            }
            else{
                if(arr[j].first -nums[i]<-1){
                    arr.push_back({nums[i], 1}); // if element is less than current number but difference is greater than 1
                }
                else{
                    arr[j].first = nums[i]; // if element is less than current number by 1 
                    arr[j].second++; // increasing subsequence length by 1
                }
                
            }
        }
        bool f= false;
        for(auto a : arr){
           //cout<<a.first<<" "<<a.second<<endl;
            if(a.second <3)return false; //some may be of only 2 and 1 size so we are returning false
        }
        return true;
    }

};