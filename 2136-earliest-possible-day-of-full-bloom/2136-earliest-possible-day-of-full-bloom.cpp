class Solution {
public:
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int cnt=0, num=0;
    priority_queue<pair<int,int>>mxhp;
    for(int i=0;i<plantTime.size();i++){
        mxhp.push({growTime[i],plantTime[i]});
    }
    while(!mxhp.empty()){
        int fst=mxhp.top().second, scnd=mxhp.top().first;
        mxhp.pop();
        num+=fst;
        cnt=max(cnt,num+scnd+1);
    }
    return cnt-1;
    
}

};