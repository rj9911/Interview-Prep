class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0  ; i<l.size() ; i++)
        {  
            priority_queue<int, vector<int>, greater<int> > pq( nums.begin()+l[i], nums.begin() + r[i]+1);
            bool temp = true;
            if(pq.size()<=2) ans.push_back(true);
            else
            { 
                int x = pq.top();
             pq.pop();
             int y = pq.top();
             int diff = y-x;
            while(pq.size()>=2)
            {
              x = pq.top();
              pq.pop();
              y = pq.top();
              if(y-x != diff) {temp = false;break;}
            }
            ans.push_back(temp);
            }
        }
        return ans;
    }

};