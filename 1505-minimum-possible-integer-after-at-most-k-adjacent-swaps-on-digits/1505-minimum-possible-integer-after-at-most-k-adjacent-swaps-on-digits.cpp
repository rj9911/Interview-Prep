class Solution {
public:
    string minInteger(string a, int k) {
        int n=a.length();
        int req=(n+1)*n/2;       // upper limit for the number of swaps that is also less than 10^9 lowering our time complexity
        if(k>req){                    // that means we can try all swaps so returning minimum of all these by sorting 
            sort(a.begin(),a.end());   
            return a;
        }
        for(int i=0;i<n-1 && k>0;i++){
            //iterate in a window of size k 
            int pos=i;
            int j;
            for(j=i+1;j<n;j++){
                //out of window bound
                if(j-i>k){break;}
                //else if we actually wanna swap, we do
                if(a[j]<a[pos]){pos=j;}
            }
            //now assuming we swapped we have pos=j
            char temp;
            for(j=pos;j>i;j--){
                //we are swapping a[j] and a[j-1] finally we will have a[pos] swapped with a[i]
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            //now update k value and do over if we wanna change the second most significant element to
            k-=pos-i;
        }
        return a;
    }

};