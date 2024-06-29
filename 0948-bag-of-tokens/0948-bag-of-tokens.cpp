class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score+=1;
                ans = max(ans,score);
                i++;
            }
            else{
                if(score>0){
                    power+=tokens[j];
                    score-=1;
                    j--;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }

};