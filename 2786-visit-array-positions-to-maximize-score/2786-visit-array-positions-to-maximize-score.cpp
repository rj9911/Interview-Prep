class Solution {
public:
    long long maxScore(vector<int>& numbersOfArray, int penalty) {
        long long size = numbersOfArray.size();
        long long table[size][2];
        table[0][1] = numbersOfArray[0];
        table[0][0] = numbersOfArray[0];
        
        int parity = numbersOfArray[0] % 2;
        if (parity == 1) {
            table[0][0] -= penalty;
        } else {
            table[0][1] -= penalty;
        }
        for (int i = 1; i < size; i++) {
            long long remainder = numbersOfArray[i];
            if (remainder % 2 != 0) {
                table[i][1] = max(table[i-1][1] + numbersOfArray[i], table[i-1][0] + numbersOfArray[i] - penalty);
                table[i][0] = table[i-1][0];
            }  else {   
                table[i][0] = max(table[i-1][0] + numbersOfArray[i], table[i-1][1] + numbersOfArray[i] - penalty);
                table[i][1] = table[i-1][1];
            }
        }
        long long uttr=max(table[size-1][0], table[size-1][1]);
        return uttr;
    }

};