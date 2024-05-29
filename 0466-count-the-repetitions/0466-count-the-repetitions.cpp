class Solution {
public:
  /*  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();
        
        // Step 1: Count how many full sequences of s2 can be formed from s1
        vector<int> repeatCount(len2 + 1, 0), nextIndex(len2 + 1, 0);
        int j = 0, count = 0;
        
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        count++;
                    }
                }
            }
            repeatCount[k] = count;
            nextIndex[k] = j;
            
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] == j) {
                    int interval = k - start;
                    int repeatInterval = (n1 - start) / interval;
                    int remaining = (n1 - start) % interval;
                    
                    return (repeatInterval * (count - repeatCount[start]) + repeatCount[start + remaining]) / n2;
                }
            }
        }
        
        return repeatCount[n1] / n2;
    }*/
    int getMaxRepetitions(string& georgia_pat, int georgia_rep, string& john_pat, int john_rep) {

    if (georgia_rep <= 0 || john_rep <= 0) {
        throw std::invalid_argument("n1 and n2 must be positive integers.");
    }
    if (georgia_pat.empty() || john_pat.empty()) {
        throw std::invalid_argument("s1 and s2 cannot be empty strings.");
    }

    const int pat_len1 = georgia_pat.size(), pat_len2 = john_pat.size();
    
    std::vector<int> repeat_count(pat_len2 + 1, 0), next_index(pat_len2 + 1, 0);
    int sec_index = 0, count = 0;
    
    for (int k_index = 1; k_index <= georgia_rep; ++k_index) {
        for (int index = 0; index < pat_len1; ++index) {
            if (georgia_pat[index] == john_pat[sec_index]) {
                sec_index++;
                if (sec_index == pat_len2) {
                    sec_index = 0;
                    count++;
                }
            }
        }
        repeat_count[k_index] = count;
        next_index[k_index] = sec_index;
        
        for (int start = 0; start < k_index; ++start) {
            if (next_index[start] == sec_index) {
                int interval = k_index - start;
                int repeat_interval = (georgia_rep - start) / interval;
                int remaining = (georgia_rep - start) % interval;
                
                return (repeat_interval * (count - repeat_count[start]) + repeat_count[start + remaining]) / john_rep;
            }
        }
    }
    
    return repeat_count[georgia_rep] / john_rep;
}

};