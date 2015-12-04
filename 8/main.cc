/*************************************************************************
 * File Name:    main.cc
 * Author:       hongchunxiao
 * Mail:         hongchunxiao@360.cn
 * Created  Time: 2015/12/02 09:49:33 (Wednesday December)
 * Modified Time: 2015/12/02 09:49:33 (Wednesday December)
 * 
 * Description:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
  int start;
  int end;

  Interval(int _start, int _end): start(_start), end(_end) {
  }

  void set(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

//element in vec is sorted and has not overlap
int InsertInterval(const vector<Interval>& vec, Interval& insert, vector<Interval>& new_vec)
{
  new_vec.clear();
  if (vec.size() == 0) {
    new_vec.push_back(insert);
  }

  bool has_insert = false;
  for (size_t i = 0; i < vec.size(); i++) {
    if (has_insert == true) {
      new_vec.push_back(vec[i]);
    } else {
      if (vec[i].end < insert.start) {
        new_vec.push_back(vec[i]);
      } else if (vec[i].start > insert.end) {
        new_vec.push_back(insert);
        new_vec.push_back(vec[i]);
        has_insert = true;
      } else {
        insert.start = min(vec[i].start, insert.start);
        insert.end = max(vec[i].end, insert.end);
      }
    }
  }

  if (has_insert == false) new_vec.push_back(insert);
  return 0;
}

void test(const vector<Interval>& vec, Interval& insert, vector<Interval>& result)
{
  cout << "input:" << endl;
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i].start << ", " << vec[i].end << endl;
  }
  cout << "insert: " << insert.start << ", " << insert.end << endl;

  InsertInterval(vec, insert, result);
  cout << "output:" << endl;
  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i].start << ", " << result[i].end << endl;
  }
  cout << endl;
}

int main()
{
  vector<Interval> result;

  vector<Interval> vec;
  vec.push_back(Interval(1, 5));
  vec.push_back(Interval(7, 10));
  Interval insert(4, 9);
  test(vec, insert, result);

  vec.clear();
  vec.push_back(Interval(1, 5));
  vec.push_back(Interval(7, 10));
  vec.push_back(Interval(12, 13));
  insert.set(-1, 0);
  test(vec, insert, result);

  vec.clear();
  vec.push_back(Interval(1, 5));
  vec.push_back(Interval(7, 10));
  vec.push_back(Interval(12, 13));
  insert.set(15, 16);
  test(vec, insert, result);

  vec.clear();
  vec.push_back(Interval(1, 5));
  vec.push_back(Interval(7, 10));
  vec.push_back(Interval(12, 13));
  vec.push_back(Interval(19, 20));
  insert.set(15, 16);
  test(vec, insert, result);

  vec.clear();
  vec.push_back(Interval(1, 5));
  vec.push_back(Interval(7, 10));
  vec.push_back(Interval(12, 13));
  vec.push_back(Interval(19, 20));
  insert.set(9, 15);
  test(vec, insert, result);
  return 0;
}
