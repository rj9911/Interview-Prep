class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int idx = 0;
        int cnt = 0;
        for(int i=0;i<nums.size() && idx<n;i++)
        {
            int ptr = i;
            if(nums[i]==groups[idx][0])
            {
                int siz = groups[idx].size();
                int flg = 0;
                int flg2 = 0;
                for(int j=0;j<siz && i<nums.size();j++)
                {
                    if(nums[i]!=groups[idx][j])
                    {
                        flg = 1;
                        break;
                    }
                    if(j==siz-1)
                    flg2 = 1;
                    i++;
                }
                if(!flg && flg2)
                {
                    cnt++;
                    idx++;
                    i--;
                }
                else
                i = ptr;
            }
        }
        if(cnt>=n)
        return true;
        return false;
    }

};