
#include <forward_list>
#include <iostream>
#include <iterator>
using namespace std;

int main() {

  forward_list<string> laser{"range_max", "range_min", "angle_max",
                             "angle_min"};

  auto laser_front = laser.begin();
  cout << *laser_front << '\n';

  laser_front = next(laser_front, 2);
  cout << *laser_front << '\n';

  laser.reverse();
  laser_front = laser.begin();
  laser_front = next(laser_front, 2);
  cout << *laser_front << '\n';
  return 0;
}