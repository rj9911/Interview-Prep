class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        long long ans = 0;
        string a = "101",b = "010";
        vector<long long> prev(4,0) , curr(4,0);

        prev[0] = 1;

        for(int i = 1;i<=n;i++){
            curr[0] = 1;
            for(int j = 1;j<=3;j++){
                long long nt = prev[j];
                long long t = 0;
                if(s[i-1] == a[j-1]){
                    t = curr[j-1];
                }
                curr[j] = nt + t;
            }

            prev = curr;
        }
        ans += prev[3];

        for(int i = 0;i<4;i++){
            prev[i] = 0;
            curr[i] = 0;
        }
        prev[0] = 1;
        for(int i = 1;i<=n;i++){
            curr[0] = 1;
            for(int j = 1;j<=3;j++){
                long long nt = prev[j];
                long long t = 0;
                if(s[i-1] == b[j-1]){
                    t = curr[j-1];
                }

                curr[j] = nt + t;
            }
            prev = curr;
        }
        ans += prev[3];

        return ans;
    }

};