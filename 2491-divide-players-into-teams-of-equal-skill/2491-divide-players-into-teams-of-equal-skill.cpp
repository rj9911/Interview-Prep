class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long result = 0;
        int pair = skill[0] + skill[n-1];

        int i = 0, j = n-1;
        while(i < j){
            if(skill[i] + skill[j] == pair){
                int temp = skill[i] * skill[j];
                result += temp;
                i++; j--;
            }
            else{
                return -1;
            }
        }

        return result;
    }

};