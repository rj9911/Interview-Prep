class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0; 
        
        while (target > 1) {
            if (maxDoubles > 0 && target % 2 == 0) {
                target /= 2;   
                maxDoubles--;  
                moves++;        
            }
            else if (maxDoubles > 0 && target % 2 != 0) {
                target--;      
                moves++;  
            }
            else {
                moves += (target - 1); 
                target = 1;         
            }
        }
        return moves;
    }

};