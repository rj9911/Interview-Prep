class Solution {
public:
bool check(int cap,int days,vector<int>& wt){
        int day =1;
        int curr=0;
        for(int i:wt){
            if(cap<i) return false;
            curr=curr+i;
            if(curr>cap){
                day++;
                curr=i;
            }
        }

        return day<=days?true:false;
}
int shipWithinDays(vector<int>& wt, int days) {
        int max_boxes = ceil(wt.size()*1.0/days);
        int cap=0;
        int pre_max=INT_MAX,pre_id=-1;

        priority_queue <int> pq;
        for(int i:wt) pq.push(i);
        for(int i=0;i<max_boxes;i++){
            cap += pq.top();
            pq.pop();
        }

        int st =0;
        int en = cap;

        while(st<en){
            int mid = (st+en)/2;

            if(check(mid,days,wt)){
                en = mid;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }

};