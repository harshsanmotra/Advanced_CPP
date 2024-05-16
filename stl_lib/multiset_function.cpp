#include <iostream>
#include <set>

using namespace std;

int main() {
  // greater<int> stores elements in descending order
  multiset<int, greater<int>> s1;

  // insert elements in random order
  s1.insert(100);
  s1.insert(1);
  s1.insert(80);
  s1.insert(80);
  s1.insert(180);
  s1.insert(0);
  s1.insert(510);

  // trying to add redundant keys
  s1.insert(510);
  s1.insert(100);

  // printing set s1
  multiset<int, greater<int>>::iterator itr;
  cout << "\nThe multiset s1 is : \n";
  for (itr = s1.begin(); itr != s1.end(); itr++) {
    cout << *itr << " ";
  }
  cout << endl;

  // assigning the elements from s1 to s2
  multiset<int> s2(s1.begin(), s1.end());
  // s3 is a copy of s2
  multiset<int, greater<int>> s3(s1.begin(), s1.end());
  // print all elements of the set s2
  cout << "\nThe multiset s2 after assign from s1 is : \n";
  for (itr = s2.begin(); itr != s2.end(); itr++) {
    cout << *itr << " ";
  }
  cout << endl;

  cout << "\nThe multiset s3 after assign from s1 is : \n";
  for (itr = s3.begin(); itr != s3.end(); itr++) {
    cout << *itr << " ";
  }

  cout << endl;

  // remove all elements less than 100 in s2
  cout << "\ns2 after removal of elements less than 100 "
          ":\n";
  s2.erase(s2.begin(), s2.find(100));
  for (itr = s2.begin(); itr != s2.end(); itr++) {
    cout << *itr << " ";
  }

  cout << "\n \n";
  cout << "After removal of 510 from s2" << endl;
  // remove element with value 510 in s2
  s2.erase(510);
  for (itr = s2.begin(); itr != s2.end(); itr++) {
    cout << *itr << " ";
  }

  cout << "\n \n";

  // lower bound and upper bound for set s1
  cout << "s3.lower_bound(80) : \n" << *s3.lower_bound(80) << endl;
  cout << "s3.upper_bound(80) : \n" << *s3.upper_bound(80) << endl;

  return 0;
}

/*
insert(k): inserts k as per the ascending/descending order which is mentioned at
the time of declaring the multiset. begin(): returns an iterator to the first
element of the multiset. end(): returns an iterator to the past-the-end element
of the multiset. The past-the-end element is the theoretical element that would
follow the last element in the set container. erase(k): erases all the keys with
value k(recall here key==value) lower_bound(k): returns iterator to the nth
element which is equal to k(if present) or to the element which is right next to
the kth element if existed in the multiset. upper_bound(k): return the iterator
to the element right next to the element(which is equal to k even if k is
present in the multiset).
*/