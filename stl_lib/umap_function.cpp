#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, double> umap;

  // inserting values by using [] operator
  umap["one"] = 1.1;
  umap["two"] = 2.22;
  umap["three"] = 3.333;
  umap["four"] = 4.4444;
  umap["five"] = 5.55555;
  umap["one_"] = 1.;
  umap["two_"] = 2.2;
  umap["three_"] = 3.33;
  umap["four_"] = 4.444;
  umap["five_"] = 5.5555;
  umap["one__"] = 11;
  umap["two__"] = 222;
  umap["three__"] = 3.333;
  umap["four__"] = 4.444;
  umap["five__"] = 5.5555;
  umap["one___"] = 11;
  umap["two___"] = 222;
  umap["three___"] = 3.333;
  umap["four___"] = 4.444;
  umap["five___"] = 5.5555;
  umap["one____"] = 11;
  umap["two____"] = 222;
  umap["three____"] = 3.333;
  umap["four____"] = 4.444;
  umap["five____"] = 5.5555;
  umap["one_______"] = 11;
  umap["two_______"] = 222;
  umap["three_______"] = 3.333;
  umap["four_______"] = 4.444;
  umap["five_______"] = 5.5555;
  umap["one_______________"] = 11;
  umap["two_______________"] = 222;
  umap["three_______________"] = 3.333;
  umap["four_______________"] = 4.444;
  umap["five_______________"] = 5.5555;

  // inserting value by insert function
  umap.insert(make_pair("six", 6.66));

  string key = "seven";

  // If key not found in map iterator to end is returned
  if (umap.find(key) == umap.end())
    cout << key << " not found\n\n";

  // If key found then iterator to that key is returned
  else
    cout << "Found " << key << "\n\n";

  key = "one";
  if (umap.find(key) == umap.end())
    cout << key << " not found\n";
  else
    cout << "Found " << key << endl;

  // iterating over all value of umap
  unordered_map<string, double>::iterator itr;
  cout << "\nAll Elements : \n";
  for (itr = umap.begin(); itr != umap.end(); itr++) {
    // itr works as a pointer to pair<string, double>
    // type itr->first stores the key part and
    // itr->second stores the value part
    cout << itr->first << " " << itr->second << endl;
  }

  int n = umap.bucket_count();
  cout << "Total no. of buckets/bunches in which key are organised: " << n
       << endl;

  int number = umap.bucket("five");
  cout << "Bucker Number : " << number << endl;

  auto z = umap.bucket_size(number);
  cout << "bucket size in which key are organised: " << z << endl;

  n = umap.count("two_");
  cout << "Total no. of elements in which key are organised: " << n << endl;
}

// at(): Shows elements at that location.

// begin(): Returns an iterator pointing to the first element in the container.

// end(): Returns an iterator pointing to the position past the last element in
// the container in the unordered_map container

// bucket(): Returns the bucket number where the element with the key k is
// located in the map.

// bucket_count: bucket_count is used to count the total no. of buckets in the
// unordered_map.

// bucket_size: Returns the number of elements in each bucket of the
// unordered_map.

// count(): Count the number of elements present in an unordered_map with a
// given key.

// equal_range: Return the bounds of a range that includes all the elements in
// the container with a key that compares equal to k.