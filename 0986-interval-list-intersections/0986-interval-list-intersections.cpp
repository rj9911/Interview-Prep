class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0, j= 0;

        while( i < firstList.size() and j < secondList.size()) {
            if(firstList[i][1] < secondList[j][0]) {
                i++;
            }
            else if(secondList[j][1] < firstList[i][0]) {
                j++;
            }
            else {
                int start= max(firstList[i][0], secondList[j][0]);
                int end= min(firstList[i][1], secondList[j][1]);
                if(secondList[j][1] >= firstList[i][1]) {
                    secondList[j][0]= end;
                    i++;
                } else {
                    firstList[i][0]= end;
                    j++;
                }
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};