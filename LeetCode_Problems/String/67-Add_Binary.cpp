#include <string>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::string result;

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (true) {
      if ((i < 0) && (j < 0) && (carry == 0)) {
        break;
      }

      if (i >= 0) {
        carry += a[i] - '0';
        --i;
      }

      if (j >= 0) {
        carry += b[j] - '0';
        --j;
      }

      result += carry % 2 + '0';
      carry /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};