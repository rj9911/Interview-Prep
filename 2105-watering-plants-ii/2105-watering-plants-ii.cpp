class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        int currCapA = capacityA, currCapB = capacityB;
        int refCount = 0;
        int i = 0, j = plants.size() - 1;

        while(i <= j) {
            // Alice can water
            if(currCapA >= plants[i]) {
                currCapA -= plants[i];
            } else {
                if(i == j) {
                    if (currCapB >= plants[i]) {
                        break;
                    }
                }
                currCapA = capacityA;
                currCapA -= plants[i];
                refCount++;
            }

            if(currCapB >= plants[j]) {
                currCapB -= plants[j];
            } else {
                if(i == j) {
                    break;
                }
                currCapB = capacityB;
                currCapB -= plants[j];
                refCount++;
            }

            i++;
            j--;
        }  
        return refCount;
    }

};