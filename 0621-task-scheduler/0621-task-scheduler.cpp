class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto c:tasks){
            m[c]++;
        }
        priority_queue<int>pq;
        for(auto i:m){
            //cout<<i.second<<endl;
            pq.push(i.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            for(auto i:temp){
                if(i>0){
                    pq.push(i);
                }
            }
            //important
            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};