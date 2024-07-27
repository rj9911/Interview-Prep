class Solution {
public:
    int maximumLength(vector<int>& numbers) {
        long long result = 0;
        map<long long, long long> numberCountMap;
        
        for(int num : numbers) {
            numberCountMap[num]++;
        }
        
        if(numbers.size() < 3) {
            return 1;
        }
        
        if(numberCountMap.find(1) != numberCountMap.end()) {
            result = max(result, (numberCountMap[1] % 2 == 0 ? numberCountMap[1] - 1 : numberCountMap[1]));
        }
        
        unordered_set<long long> visitedNumbers;
        
        for(auto it : numberCountMap) {
            long long currentNumber = it.first, exponent = 2, count = 2;
            
            visitedNumbers.insert(it.first);
            
            if(it.second < 2) {
                continue;
            }
    
            long long temp = currentNumber * currentNumber;
            
            while(visitedNumbers.find(temp) == visitedNumbers.end() and numberCountMap.find(temp) != numberCountMap.end()) {
                visitedNumbers.insert(temp); 
                result = max(result, count + 1);
                
                if(numberCountMap[temp] >= 2) {
                    count += 2;
                } else {
                    break;
                }
                
                exponent <<= 1;
                temp = pow(currentNumber, exponent);
            }
        }
        
        return max(result, 1LL);
    }

};