#include "robot_commander/robot_commander.h"
#include <deque>
#include <ros/ros.h>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  my_robot.move_in_circles();

  int x = 0;
  int total_values = 0;

  std::cout << "Enter the number of heading values that you want to capture: ";
  std::cin >> total_values;

  deque<float> rValues;

  while (x < total_values) {
    rValues.push_front(my_robot.get_heading());
    cout << "Collecting heading value: " << rValues[0] << endl;

    x++;
    usleep(1000000);
  }

  // new line
  std::cout << std::endl;
  std::cout << "Displaying saved data" << std::endl;
  // ranged loop
  for (const float &i : rValues) {
    cout << "Heading value : " << i << endl;
  }

  my_robot.stop_moving();

  return 0;
}
