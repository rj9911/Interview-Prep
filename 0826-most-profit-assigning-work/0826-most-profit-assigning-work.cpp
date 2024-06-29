class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> pq; //We will store profit, difficulty
                                         // of ith job in max heap.
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> storage;
        //min heap to store the jobs whose difficulty level exceed the first job workers capability
        int totalProfit = 0, n=difficulty.size(), m=worker.size();
        sort(worker.begin(), worker.end());
        for(int i=0; i<n; i++)
        {
            if(difficulty[i] <= worker[0])
                pq.push({profit[i], difficulty[i]});
            else
                storage.push({difficulty[i], profit[i]});
        }
        for(int i=0; i<worker.size();)
        {
            if(!pq.empty())
                totalProfit += pq.top().first;
            i++; // to move to next worker, not given in for condition 
                // as otherwise we need to make checks below. 
            if(i == worker.size())
                break;
            while(!storage.empty())
            {
                if(storage.top().first <= worker[i])
                {
                    pq.push({storage.top().second,storage.top().first});
                    storage.pop();
                }
                else
                    break;
            }
        }
        return totalProfit;
    }

};