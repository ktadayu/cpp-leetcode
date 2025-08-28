#include "common.hpp"
class MyCalendarTwo {
  vector<pair<int, int>> book;
  vector<pair<int, int>> booked;

  bool is_doubly_booked(int s1, int e1, int s2, int e2) {
    return max(s1, s2) < min(e1, e2);
  }

public:
  MyCalendarTwo() = default;

  bool book(int start, int end) {
    for (const auto &q : booked) {
      if (is_doubly_booked(start, end, q.first, q.second))
        return false;
    }
    for (const auto &p : booked) {
      if (is_doubly_booked(start, end, p.first, p.second)) {
        int l = max(start, p.first);
        int r = min(end, p.second);
        booked.emplace_back(l, r);
      }
    }
    booked.emplace_back(start, end);
    return true;
  }

}

bool book(int startTime, int endTime) {
}
int main() { return 0; }
