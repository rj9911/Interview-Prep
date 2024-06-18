class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordFreq;
        int wordLen = words[0].size();
        int totalWords = words.size();
        int concatLen = wordLen * totalWords;
        vector<int> result;

        if (concatLen > s.size())
            return result;

        for (string& word : words)
            wordFreq[word]++;

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;
            int left = i, right = i, count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    window[word]++;
                    count++;

                    while (window[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        left += wordLen;
                        window[leftWord]--;
                        count--;
                    }

                    if (count == totalWords)
                        result.push_back(left);

                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }

};