class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i = 1; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < i; j++){
                if(r[i]>r[j]) cnt++;
            }
            left[i] = cnt;
        }
        for(int i = n-2; i >= 0; i--){
            int cnt = 0;
            for(int j = n-1; j > i; j--){
                if(r[i]>r[j]) cnt++;
            }
            right[i] = cnt;
        }
        int res = 0;
        for(int i = 1; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < i; j++){
                if(r[i]>r[j]) cnt += left[j];
            }
            res += cnt;
        }
        for(int i = n-2; i >= 0; i--){
            int cnt = 0;
            for(int j = n-1; j > i; j--){
                if(r[i]>r[j]) cnt += right[j];
            }
            res += cnt;
        }
        return res;
    }

};