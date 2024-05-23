class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       int n = nums1.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            int sum;
            for(int j=0;j<nums2.size();j++)
            {
                sum = 0;
                if(pq.size() == k){
                    sum = nums1[i] + nums2[j];
                    if(sum<pq.top().first)
                    {
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }else break;
                }else{
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
            }
        }
        
        while(!pq.empty())
        {
            auto it = pq.top();
            vector<int> res;
            res.push_back(it.second.first);
            res.push_back(it.second.second);
            ans.push_back(res);
            pq.pop();
        }
        return ans;


    }
};