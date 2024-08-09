class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int n = tasks.size(), ans = 0, energyLeft = 0;
        for(int i=0; i<n; i++){
            int actual = tasks[i][0];
            int mini = tasks[i][1];

            if(energyLeft < mini){
                ans += mini - energyLeft;
                energyLeft = mini - actual;
            }
            else{
                energyLeft = energyLeft - actual;
            }
        }

        return ans;
    }

};