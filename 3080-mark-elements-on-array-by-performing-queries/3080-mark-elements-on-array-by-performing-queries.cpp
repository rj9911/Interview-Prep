class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long > res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> marked;
        long long unmSum=0;
        for(int i=0;i<nums.size();i++){
            unmSum+=nums[i];
            pq.push({nums[i],i});
        }
        
        for(auto q:queries){
            int ci=q[0];
            int k=q[1];
           if(marked.count(ci)==0){ unmSum-=nums[ci];
            marked.insert(ci);
                                  }
            while(pq.size() && k>0){
                pair<int,int> tp=pq.top();
                pq.pop();
                if(marked.count(tp.second)==0){
                    // cout<<tp.second<<" ";
                    unmSum-=tp.first;
                    k--;
                    marked.insert(tp.second);
                }
                
                if(unmSum<0) unmSum=0;
            }
            // cout<<endl;
            res.push_back(unmSum);
        }
        return res;
        
    }

};