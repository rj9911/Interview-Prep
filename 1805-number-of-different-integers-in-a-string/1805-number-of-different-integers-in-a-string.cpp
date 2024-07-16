class Solution {
public:
    int numDifferentIntegers(string word) {
        string temp = "";

        unordered_map<string, int> numberBank;

        int digit = 0;

        for(char c : word){
            if(isdigit(c)){
                digit = 1;

                if(c == '0' && temp == "")
                    continue;

                temp += c;

            } else {
                if(digit && numberBank.find(temp) == numberBank.end())
                    numberBank[temp] = 1;

                temp = "";
                digit = 0;
            }
        }

        if(digit || temp != ""){
            if(numberBank.find(temp) == numberBank.end())
                numberBank[temp] = 1;
        }

        return numberBank.size();
    }

};