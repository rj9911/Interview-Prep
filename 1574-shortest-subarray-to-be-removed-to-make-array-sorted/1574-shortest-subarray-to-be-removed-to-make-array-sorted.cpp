class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = arr.size() - 1;

        while(l < r){
            if(arr[l] <= arr[l + 1] && arr[r - 1] <= arr[r]){
                l++;
                r--;
            }
            else if(arr[l] <= arr[l + 1]){
                l++;
            }
            else if(arr[r - 1] <= arr[r]){
                r--;
            }
            else{
                break;
            }
        }
        if(l >= r){
            return 0;
        }

        int minLen = min(n - 1 - l, r);
        for(int i = 0; i <= l; i++){
            while(r < n && arr[r] < arr[i]){
                r++;
            }
            minLen = min(minLen, r - i - 1);
        }
        return minLen;
    }

};