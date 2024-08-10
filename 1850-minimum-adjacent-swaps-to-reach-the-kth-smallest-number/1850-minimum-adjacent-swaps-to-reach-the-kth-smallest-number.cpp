class Solution {
public:
    int getMinSwaps(string num, int k){
     string original = num;
        // Generate the k-th permutation
        for(int i = 0; i < k;i++){
            std::next_permutation(num.begin(), num.end());
        }
        int swaps = 0;
        for(int i = 0; i < num.size();i++){
            if(original[i] != num[i]){
                int j = i;
                // Find the position of the needed character
                while(original[j] != num[i]){
                    j++;
                }
                // Perform the swaps to bring the character to the current position
                while(j > i){
                   swap(original[j], original[j - 1]);
                    swaps++;
                    j--;
                }
            }
        }
        return swaps;
    }

};