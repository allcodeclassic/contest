#include <bits/stdc++.h>
using namespace std;

struct FenwickTree2D { // BinaryIndexedTree2D
  int numRow, numColumn;
  vector<vector<int>> bit;

  FenwickTree2D(int _numRow, int _numColumn) : numRow(_numRow), numColumn(_numColumn) {
    bit.assign(numRow + 1, vector<int>(numColumn + 1));
  }

  void add(int curRow, int curColumn, int value) {
    for (int row = curRow; row <= numRow; row += row & (-row)) {
      for (int column = curColumn; column <= numColumn; column += column & (-column)) {
        bit[row][column] += value;
      }
    }
  }

  long long query(int curLeft, int curAbove, int curRight, int curBelow) {
    long long result = 0;
    for (int row = curRight; row > 0; row -= row & (-row)) {
      for (int column = curBelow; column > 0; column -= column & (-column)) {
        result += bit[row][column];
      }
    }
    for (int row = curRight; row > 0; row -= row & (-row)) {
      for (int column = curAbove - 1; column > 0; column -= column & (-column)) {
        result -= bit[row][column];
      }
    }
    for (int row = curLeft - 1; row > 0; row -= row & (-row)) {
      for (int column = curBelow; column > 0; column -= column & (-column)) {
        result -= bit[row][column];
      }
    }
    for (int row = curLeft - 1; row > 0; row -= row & (-row)) {
      for (int column = curAbove - 1; column > 0; column -= column & (-column)) {
        result += bit[row][column];
      }
    }
    return result;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int instruction, size;
  cin >> instruction >> size;
  FenwickTree2D fenwick(size, size);
  while (cin >> instruction && instruction != 3) {
    if (instruction == 1) { // add
      int row, column, value;
      cin >> row >> column >> value;
      row++; column++;
      fenwick.add(row, column, value);
    } else if (instruction == 2) { // query
      int left, above, right, below;
      cin >> left >> above >> right >> below;
      left++; above++; right++; below++;
      cout << fenwick.query(left, above, right, below) << '\n';
    }
  }
  return 0;
}
