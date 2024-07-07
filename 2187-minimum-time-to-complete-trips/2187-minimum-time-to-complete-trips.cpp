class Solution {
public:
    bool check(long long mid,vector<int>& time, int totalTrips) {
        long long trips=0;//we need to complete total trips or more but not less than total trips
        int n=time.size();
        for(int i=0; i<n; i++){
            trips += mid/(long long)time[i];
        }
        if(trips < (long long)totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        // finding maximum number in the array 
        int max=INT_MIN;
       for(int i=0; i<n; i++) {
            if(max < time[i]) max=time[i];
        }
        //binary search
        long long low=1;
        long long high= (long long)max * (long long)totalTrips;
        long long ans=-1;
        while(low <= high){
            long long mid=low+(high-low)/2;
            if(check(mid,time,totalTrips)==true){ // funcation calling
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }

};