class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (3, -1));

        dp[n-1][0] = true;      //at last index already.
        dp[n-1][1] = true;

        unordered_map<int,int> latestIndex;     // to get smallest index of same elements always.
        latestIndex[arr.back()] = n-1;

        set<int> elements;          //for fixing i < j condition and apply binary search efficiently.
        elements.insert(arr.back());

        for(int i=n-2;i>=0;i--){
            for(int isOdd=0;isOdd<2;isOdd++){
                int target = arr[i];
                int j = -1;     

                if(isOdd == 1){
                    //find x >= target
                    //simple LB(target).
                    auto it = elements.lower_bound(target);
                    if(it != elements.end()) j = latestIndex[(*it)];
                }
                else{
                    //find x <= target
                    // get LB, check if its equal to target
                    // if yes, do nothing
                    // else decreament itr, since LB would've given a number > target.
                    auto it = elements.lower_bound(target);
                    if(it != elements.end()){
                        if((*it) == arr[i]) j = latestIndex[(*it)];
                        else {
                            if(it != elements.begin()){
                                it--;
                                j = latestIndex[(*it)];
                            }
                        }                        
                    }
                    else{   
                        // what if set doesnt contains any element >= target, i.e. all are < target?
                        // in that case get the closest one. i.e. last ele of set.
                        it = elements.end();
                        it--;
                        j = latestIndex[(*it)];
                    }
                }

                //if j is possible, go to j with even jump i.e. 1 - isOdd.
                if(j != -1) dp[i][isOdd] = dp[j][1 - isOdd];
                else dp[i][isOdd] = false;
            }

            latestIndex[arr[i]] = i;        //update index 
            elements.insert(arr[i]);        //insert element
        }

        //take all elements from which we can start jump (1st jump). i.e. for which dp[i][isOdd] is true.
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += dp[i][1];       // isOdd = true
        }
        return ans;   
            //O(nlogn) + O(n)
    }

};