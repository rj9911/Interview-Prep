class Solution {
public:
  int maximumSwap(int num) {
    // Convert the number to a vector of digits
    string numStr = to_string(num);
    vector<int> digits(numStr.begin(), numStr.end());
    for (int &digit : digits) {
        digit -= '0';
    }

    // Create a vector to keep track of the maximum digit's position from the right
    int n = digits.size();
    vector<int> maxRight(n);
    int maxDigit = -1;
    int maxPos = -1;

    // Populate the maxRight array with positions of maximum digits
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] > maxDigit) {
            maxDigit = digits[i];
            maxPos = i;
        }
        maxRight[i] = maxPos;
    }

    // Find the best swap opportunity
    for (int i = 0; i < n; ++i) {
        if (digits[i] < digits[maxRight[i]]) {
            // Perform the swap
            int swapIdx = maxRight[i];
            swap(digits[i], digits[swapIdx]);
            break;
        }
    }

    // Convert the vector of digits back to an integer
    int result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}


};