#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

private:
  unordered_map<char, int> roman_numbers;

public:
  Solution() {
    roman_numbers.insert({'I', 1});
    roman_numbers.insert({'V', 5});
    roman_numbers.insert({'X', 10});
    roman_numbers.insert({'L', 50});
    roman_numbers.insert({'C', 100});
    roman_numbers.insert({'D', 500});
    roman_numbers.insert({'M', 1000});
  }

  int roman_to_integer(string roman) {
    int interger = 0;

    if (roman.size() > 1) {
      int i;
      for (i = 0; i < roman.size() - 1; i++) {
        char curr_letter = roman[i];
        char next_letter = roman[i + 1];

        if (roman_numbers.at(curr_letter) >= roman_numbers.at(next_letter)) {
          interger += roman_numbers.at(curr_letter);
        } else {
          interger -= roman_numbers.at(curr_letter);
        }
      }
      interger += roman_numbers.at(roman.at(roman.size() - 1));
    } else {
      interger = roman_numbers.at(roman[0]);
    }

    return interger;
  }
};

int main() {
  Solution solution;

  int interger = solution.roman_to_integer("MCMXCIV");

  cout << interger << endl;

  return EXIT_SUCCESS;
}