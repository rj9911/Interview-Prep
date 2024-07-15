class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size(); 
       unordered_map<long long,long long>mp1;
       unordered_map<long long,long long>mp2;
       for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
            long long mul=(long)((long)nums1[i]*(long)nums1[j]);
            mp1[mul]++;
         }
       }
       for(int i=0;i<m-1;i++){
         for(int j=i+1;j<m;j++){
            mp2[(long)((long)nums2[i]*(long)nums2[j])]++;
         }
       }
       long long cnt=0;
       for(int i=0;i<m;i++){
        if(mp1.find((long)nums2[i]*(long)nums2[i])!=mp1.end()){
            cnt+=mp1[(long)nums2[i]*(long)nums2[i]];
        }
       }
         for(int i=0;i<n;i++){
        if(mp2.find((long)nums1[i]*(long)nums1[i])!=mp2.end()){
            cnt+=mp2[((long)nums1[i]*(long)nums1[i])];
        }
       }
       return (int)cnt;


    }

};