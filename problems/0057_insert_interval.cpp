#include "common.hpp"

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  for (auto i : newInterval) {
    // j[0]<=i[0]となるintervalの要素jで最大のものを取得する
    // j[1]の値によって場合わけ
    // j[1] >= i[1]ならjはiを含める
    // それ以外の場合、区間を伸ばす
    // i[1] <k[1]なる
  }
}

int main() { return 0; }
