class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int> m;

        for(int i=0;i<banned.size();i++){
            m[banned[i]]++;
        }

        int i =1;
        int sum=0;
        int cnt=0;

        while(i<=n){
            if(m.find(i)==m.end()  && sum<=maxSum){
                sum+=i;
                cnt++;

                if(sum>maxSum){
                    return cnt-1;
                }
            }
            i++;
        }

        return cnt;
    }
};