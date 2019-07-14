#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/longest-word-in-dictionary/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestWord(vector<string>& words) {
        // words not empty
        unordered_set<string> seen;
        sort(words.begin(), words.end());
        string longest = words[0];
        unsigned long ml = longest.length();
        for (auto& w: words) {
            if (w.length() == 1) {
                seen.insert(w);
            } else if (seen.count(w.substr(0, w.length() - 1))) {
                seen.insert(w);
                if (w.length() > ml) {
                    longest = w;
                    ml = w.length();
                }
            }
        }
        return longest;
    }
};

void test1() {
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << "world ? " << Solution().longestWord(words) << endl;
}

void test2() {

}

void test3() {

}