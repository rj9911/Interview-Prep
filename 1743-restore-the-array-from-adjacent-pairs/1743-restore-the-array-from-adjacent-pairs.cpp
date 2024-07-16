class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> m;
        //map adjacent pairs
        for(auto &i:pairs){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int> res(size(pairs)+1);
        int i = 0;

        for(auto &it:m){
            if (it.second.size() == 1)
            {
                res[i++] = it.first; //first element
                res[i++] = it.second[0];//first's adj = second element
                break;
            }
        }
        int prev = res[i-1], prevAdj = res[i-2];//prev has always two adjacent one before it, one after it i.e the curr element!!

        while( i < size(res))
        {
            int curr = m[prev][0]; //prev has 2 adjacent element

            if (curr == prevAdj)   curr = m[prev][1]; //next adjacent element of prev!
            res[i++] = curr;
            prevAdj = prev;
            prev = curr;
        } 
        return res;
    }

};