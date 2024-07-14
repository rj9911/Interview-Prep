class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        vector<int> temp;
        for (int i = 0; i < s.length(); i++) {
            int numOfConvert = 0;
            if (int(t[i]) >= int(s[i])) numOfConvert = int(t[i]) - int(s[i]);
            else numOfConvert = 26 + int(t[i]) - int(s[i]);
            temp.push_back(numOfConvert);
        }
        //filter temp
        vector<int> end(temp.size(), 0);
        map<int, int> data;
        for (int i = 0; i < temp.size(); i++) {
            data[temp[i]] = 0;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] % 26 == 0) continue;
            if (data[temp[i]] == 0) data[temp[i] % 26]++;
            else {
                data[temp[i] % 26]++;
                temp[i] = temp[i] + 26 * (data[temp[i] % 26] - 1);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            // cout << temp[i] << " ";
            if (temp[i] > k) return false;
        }
        return true;
    }

};