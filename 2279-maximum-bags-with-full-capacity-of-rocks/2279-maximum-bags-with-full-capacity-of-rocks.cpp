class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<capacity.size();i++)
        {
            int diff=capacity[i]-rocks[i];
            pq.push(diff);
        }
        int cnt=0;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();


            int c=ar-x;
            ar=ar-x;
            
            if(c<0)
                break;
            cnt++;
            }
        return cnt;
    }

};