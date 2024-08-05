class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int i = 0, count=0, start = 0, end = 0;
        while(i<clips.size()){
            bool flag = false;
            while(i<clips.size() and clips[i][0]<=start){
                end = max(end,clips[i][1]);
                i++;
                flag = true;
            }
            count++;
            start = end;
            if(end>=time) return count;
            if(!flag) return -1;
        }
        if(end>=time) return count;
        return -1;
    }

};