#include "common.hpp"

static constexpr double epsilon = 1e-6;

vector<double> appOperators(double a, double b) {
  vector<double> res;
  res.push_back(a + b);
  res.push_back(a - b);
  res.push_back(b - a);
  res.push_back(a * b);
  if (fabs(b) > epsilon) {
    res.push_back(a / b);
  }
  if (fabs(a) > epsilon) {
    res.push_back(b / a);
  }

  return res;
}

bool judgePoint24(vector<double> &cards) {
  if (cards.size() == 1) {
    return fabs(cards[0] - 24.0) < epsilon;
  }

  for (size_t i = 0; i < cards.size(); ++i) {
    for (size_t j = i + 1; j < cards.size(); ++j) {
      double a = cards[i], b = cards[j];
      vector<double> nCards;
      for (size_t k = 0; k < cards.size(); k++) {
        if (k != i && k != j) {
          nCards.push_back(cards[k]);
        }
      }
      vector<double> ops = appOperators(a, b);
      for (double res : ops) {
        nCards.push_back(res);
        if (judgePoint24(nCards)) {
          return true;
        }
        nCards.pop_back();
      }
    }
  }

  return false;
}

bool judgePoint24(vector<int> &cards) {
  vector<double> nCards(cards.begin(), cards.end());
  return judgePoint24(nCards);
}

int main() {
  vector<int> cards = {1, 7, 4, 5};
  bool res = judgePoint24(cards);
  cout << res << endl;

  return 0;
}
