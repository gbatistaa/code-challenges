#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct number {
  int value;
  int index;
} Number;

vector<int> two_sum(int target, vector<int> &nums) {
  vector<int> indexes;
  unordered_map<int, Number> nums_hash_map;

  // Hashing the vector numbers with its complement
  for (int i = 0; i < nums.size(); i++) {
    Number num = {
        nums.at(i),
        i,
    };

    // Calculate the current number complement and hash insert:
    int complement = target - num.value;
    nums_hash_map[complement] = num;
  }

  return indexes;
}

int main() { return EXIT_SUCCESS; }