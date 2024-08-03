class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps = 0;

        //using hashMap to store the value with its index.
        unordered_map<int,int> mp;
        for(int i=0; i<row.size(); i++)  {
            mp[row[i]] = i;
        }    

        for(int i=0; i<row.size()-1; i+=2)    {
            int first = row[i];
            int second;
            
            // if element is even then partner odd, vice versa
            if(first%2==0)  {
                second = first + 1;
            }
            else {
                second = first - 1;
            }
            
            //perform a swap when its needed
            if(row[i+1] != second)  {
                //incrementing swaps variable  each time
                swaps++;
                //swapping the i+1 position element with the partner 
                int temp = row[i+1];
                row[i+1] = row[mp[second]];
                row[mp[second]] = temp;
                //updating indexes in the map
                mp[temp] = mp[second];
                mp[second] = i+1;
            }
        }

        return swaps;
    }

};