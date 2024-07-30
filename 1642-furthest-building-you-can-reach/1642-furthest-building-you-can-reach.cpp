class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int l) {
        priority_queue<int>pq;
        int n = heights.size();
        int i;
        for(i=0;i<n-1;i++){
             int diff = heights[i+1]-heights[i];
             if(diff>0){
                 if(bricks>=diff){
                     bricks-=diff;
                     pq.push(diff);
                 }
                 else if(l>0){
                    if(!pq.empty()&&pq.top()>diff){
                        int top = pq.top();
                        bricks += top-diff;
                        pq.pop();
                        pq.push(diff);
                        l--;
                    }else{
                        l--;
                    }
                 }else{
                     break;
                 }
             }
        }
        return i;
    }

};