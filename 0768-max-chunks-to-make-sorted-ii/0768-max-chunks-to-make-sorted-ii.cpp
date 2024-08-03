class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // vector 'v' will be the sorted version of the original vector
        vector<int>v=arr;
        
        // sort vector 'v'
        sort(v.begin(),v.end());
        
        // 'sum' will be the running sum of the partitions
        long long sum=0;
        
        // prefix[i] = arr[0]+arr[1]+....+arr[i].
        vector<long long>prefix(arr.size());
        for(int i=0;i<v.size();i++) {
            prefix[i]=(i>0?prefix[i-1]+v[i]:v[i]);
        }
        
        // 'count' will be our answer
        // 'low' is the starting index of the current partition.
        int count=0,low=0;
        
        for(int i=0;i<arr.size();i++) {
            // calculate the running sum
            sum+=arr[i];
            
            // if at any index the running sum becomes equal to the prefix sum of that partition that means we've reached the end of a valid partition
            if((low==0 && sum==prefix[i]) || (low>0 && sum==prefix[i]-prefix[low-1])) {
                
                // so increment the chunk count as we've detected one more partition
                count++;
                
                // according to the definition of 'low' , it should be set to the next index as it will be the starting index of the next partition.
                low=i+1;
                
                // set 'sum' = 0 as we are going to start a fresh/new partition so it will cover the fresh sum of the next partition
                sum=0;
            }
        }
        
        // finally return the answer
        return count;
    }

};