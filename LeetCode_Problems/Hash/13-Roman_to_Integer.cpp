#include <string>
#include <unordered_map>

class SolutionWithObservation {
 public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> hashMap;
    hashMap['I'] = 1;
    hashMap['V'] = 5;
    hashMap['X'] = 10;
    hashMap['L'] = 50;
    hashMap['C'] = 100;
    hashMap['D'] = 500;
    hashMap['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (i != s.length() - 1 && hashMap[s[i]] < hashMap[s[i + 1]]) {
        ans -= hashMap[s[i]];
      } else {
        ans += hashMap[s[i]];
      }
    }

    return ans;
  }
};

class SolutionBruteForce {
 public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> hashMap;
    hashMap['I'] = 1;
    hashMap['V'] = 5;
    hashMap['X'] = 10;
    hashMap['L'] = 50;
    hashMap['C'] = 100;
    hashMap['D'] = 500;
    hashMap['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      if ((i != s.length() - 1) &&
              (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
          (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
          (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
        ans -= hashMap[s[i]];
      } else {
        ans += hashMap[s[i]];
      }
    }

    return ans;
  }
};