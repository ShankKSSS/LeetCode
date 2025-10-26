#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string result = "";

        int count = 1;
        for (int i = 1; i <= prev.size(); i++) {
            // If current char is same as previous, increment count
            if (i < prev.size() && prev[i] == prev[i - 1]) {
                count++;
            } else {
                // Append the count and digit to result
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        return result;
    }
};
