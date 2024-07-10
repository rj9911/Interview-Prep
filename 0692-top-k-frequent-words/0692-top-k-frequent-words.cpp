class Solution {
public:
    static bool cmp(pair<int,string> i, pair<int,string> j)
    {
        if(i.first!=j.first)
            return i.first>j.first;
        else
        {
            return i.second<j.second;
        }
    }
    vector<string> topKFrequent(vector<string>& w, int k) {
        
        unordered_map<string,int> m; //create a map to store the frequency of every string
        for(auto it:w)
            m[it]++;
        
        deque<pair<int,string>> dq;   //we create a deque and sort it according to frequency and lexographical order
        
        for(auto it:m)
            dq.push_back({it.second,it.first});
        
        sort(dq.begin(),dq.end(),cmp);  //using the comparator function we sort it according to frequencies and if frequency is same then we sort according to lexographical order
        
        vector<string> ans;
        while(k--)            //  for k times pick the top element from deque and pop it after pushing in ans vector
        {
            string s = dq.front().second;
            dq.pop_front();
            ans.push_back(s);
            
        }
        return ans;
    }
};