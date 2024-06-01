class Solution {
public:
    int longestMountain(vector<int>& elements) {
        int size=elements.size();
        vector<int> lis(size);
        lis[0]=1;
        
        for(int i=1;i<size;i++){
            int maxyet=0;
            if(elements[i-1]<elements[i]){
                maxyet=max(maxyet,lis[i-1]);
            }
            lis[i]=maxyet+1;
        }
        
        vector<int> ldp(size);
        ldp[size-1]=1;
        
        for(int i=size-2;i>=0;i--){
            if(elements[i+1]<elements[i]){
                ldp[i]=max(ldp[i],ldp[i+1]);
            }
            ldp[i]+=1;
        }
        int ans=0;
        for(int i=0;i<size;i++){
            if(lis[i]>1 && ldp[i]>1){
                ans=max(ans,(lis[i]+ldp[i]-1));
            }
        }
        return ans;
    }

};