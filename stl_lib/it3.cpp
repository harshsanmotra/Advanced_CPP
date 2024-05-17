#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7}; // create a vector
  vector<int>::iterator i, j; // defines an iterator i to the vector of integers
  cout << "The vector we have : ";
  for (i = v.begin(); i != v.end(); i++) {
    cout << *i << " ";
  }
  cout << "\n";

  i = v.begin();
  cout << "Begin() : " << *i << endl;
  /* i now points to the beginning of the vector v */

  advance(i, 5);
  cout << "Advance by 5 : " << *i << endl;

  advance(i, -1);
  cout << "Move back by 1 : " << *i << endl;

  i = v.begin();
  j = v.end();

  cout << "Distance between begin and end : " << distance(i, j) << endl;
  cout << "i : " << *i << endl;
  next(i, 4);
  cout << "4 elements next to i's current position(which is begin here) : "
       << *next(i, 4) << endl;
  cout << "i : " << *i << endl;

  advance(i, 5);
  cout << "i : " << *i << endl;

  cout << "4 elements previous to i's current position(which is at 6 here) : "
       << *prev(i, 4) << endl;
  cout << "i : " << *i << endl;
  return 0;
}

// advance(k): advance iterator by k positions
// distance(): distance between two positions
// next(iterator, n): returns the value of element n times on succession with
// iterator's current position prev(iterator, n): returns the value of element n
// times on previous with iterator's current position begin(): return first
// element of the container
// end(): returns the last of the container