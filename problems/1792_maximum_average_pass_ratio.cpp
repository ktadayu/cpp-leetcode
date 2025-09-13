#include "common.hpp"
using namespace std;

long double calc(vector<vector<int>> &classes, int i) {
  int a = classes[i][0], b = classes[i][1];
  long double delta = (long double)(b - a) / (long double)(b * (b + 1));
  return delta;
}

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {

  int n = classes.size();
  long double sum = 0.0L;
  for (auto &c : classes) {
    sum += (long double)c[0] / (long double)c[1];
  }
  auto lambda = [&](int a, int b) {
    return calc(classes, a) < calc(classes, b);
  };
  priority_queue<int, vector<int>, function<bool(int, int)>> pq(lambda);
  for (int i = 0; i < n; ++i) {
    pq.push(i);
  }
  while (extraStudents-- > 0) {
    int i = pq.top();
    pq.pop();
    sum += (long double)calc(classes, i);
    classes[i][0] += 1;
    classes[i][1] += 1;
    pq.push(i);
  }
  return (double)(sum / n);
}

int main() {
  vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
  int extraStudents = 2;
  double k = maxAverageRatio(classes, extraStudents);
  cout << k << endl;

  return 0;
}
