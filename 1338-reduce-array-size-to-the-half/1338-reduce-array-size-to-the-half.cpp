class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        // count variable for storing the number of elements that need to be removed
        int count=0;
        unordered_map<int,int> mp;
        
		// Storing frequency of each element in map
        for(auto i: arr){
            mp[i]++;
        }
        
        // Pushing elements to Priority queue according to their frequency
        priority_queue<int> pq;
        
        for(auto j: mp){
            pq.push(j.second);
        }
        
        // n is the half of size of array
        int n=arr.size()/2;
        
        while(!pq.empty() && n!=0){
            // if top element at priority queue is less than or equal to n then we need to remove that element so for that we increased the counter and update the value of n. Otherwise if it is greater than we simply increment the counter and come out of the loop and hence return the count.
            if(pq.top()<=n){
                n=n-pq.top();
                pq.pop();
                count++;
            }
            else{
               if((n-pq.top())<0){
                   count++;
                   n=0;
               }
            }
        }
        
        // Returning the final result
        return count;
        
        
    }

};