class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int start=1;
        int end=m*n;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int cnt=0;
            int total=0;
            for(int i=1;i<=m;i++)
            {
                  if(mid<=i*n && mid%i==0) cnt++;
                  total+=min(n,mid/i);
            }
              if(total<k) start=mid+1;
              else
              {
                 if(k>total-cnt && k<=total) return mid;
                 end=mid-1;
              }
        }
        return start;
    }

};