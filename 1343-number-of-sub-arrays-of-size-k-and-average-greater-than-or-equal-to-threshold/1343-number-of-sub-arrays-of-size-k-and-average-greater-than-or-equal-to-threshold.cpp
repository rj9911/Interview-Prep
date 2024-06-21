class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        if(arr.size() < k)
            return 0;
        int i = 0,j = 0,ans = 0;
        long long sum = 0;
        long long target = t * k; 
        while(j<arr.size() && i<arr.size()) {
            sum += arr[j];
            if(j - i + 1 < k)
                j++;
           else{
               if(sum >= target)
                   ans++;
               sum -= arr[i];
               i++;
               j++;
           }
        }
        return ans;
    }

};