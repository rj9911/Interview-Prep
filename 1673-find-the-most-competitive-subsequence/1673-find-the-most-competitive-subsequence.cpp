class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
       stack<int> q;

       for(int i=0;i<nums.size();i++)
       {
           while(q.size()!=0&&q.size()+nums.size()-i-1>=k&&nums[i]<q.top())
           q.pop();

           if(q.size()<k) 
           q.push(nums[i]);
       }

       vector<int> ans;

       while(q.size()!=0)
       {
           ans.push_back(q.top());
           q.pop();
       }

       reverse(ans.begin(),ans.end());

       return ans;
    }


};