class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans=0;      
        int n=reward1.size();
        priority_queue<pair<pair<int , int> , int>>pq;  

        for(int i=0;i<n;i++)            
            pq.push({{reward1[i]-reward2[i],reward1[i]},reward2[i]});

        while(!pq.empty()&&k--){
            ans=ans+pq.top().first.second;
            pq.pop();
        }   

        while(!pq.empty()){
            ans=ans+pq.top().second;
            pq.pop();
        }        
        return ans;
    }

};