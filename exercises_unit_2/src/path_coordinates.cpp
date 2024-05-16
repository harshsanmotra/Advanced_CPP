#include "robot_commander/robot_commander.h"
#include <ros/ros.h>
#include <set>
#include <utility>

using namespace std;

void printPair(const pair<float, float> &p) {
  cout << "(" << p.first << ", " << p.second << ")";
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "path_coordination");

  RobotCommander my_robot;

  set<pair<float, float>> coordinates;
  multiset<pair<float, float>> coordinates_ms;

  for (int i = 0; i < 4; ++i) {
    my_robot.move_forward(2); // Move forward for 2 seconds
    my_robot.stop_moving();

    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();

    coordinates.insert({x, y});
    coordinates_ms.insert({x, y});

    my_robot.turn(1.57, 1); // Turn 90 degrees
    my_robot.stop_moving();
  }

  cout << "\nThe set after moving forward is : \n";
  for (const auto &pair : coordinates) {
    printPair(pair);
    cout << " ";
  }
  cout << endl;

  cout << "\nThe multiset set after moving forward is : \n";
  for (const auto &pair : coordinates_ms) {
    printPair(pair);
    cout << " ";
  }
  cout << endl;

  for (int i = 0; i < 4; ++i) {
    my_robot.move_backwards(2); // Move forward for 2 seconds
    my_robot.stop_moving();

    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();

    coordinates.insert({x, y});
    coordinates_ms.insert({x, y});

    my_robot.turn(1.57, 1); // Turn 90 degrees
    my_robot.stop_moving();
  }

  cout << "\nThe set after moving backward is : \n";
  for (const auto &pair : coordinates) {
    printPair(pair);
    cout << " ";
  }
  cout << endl;

  cout << "\nThe multiset set after moving backward is : \n";
  for (const auto &pair : coordinates_ms) {
    printPair(pair);
    cout << " ";
  }
  cout << endl;
  cout << "Program End!!" << endl;

  return 0;
}