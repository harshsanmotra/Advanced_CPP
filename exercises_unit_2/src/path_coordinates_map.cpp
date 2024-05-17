#include "robot_commander/robot_commander.h"
#include <map>
#include <ros/ros.h>
#include <utility>

using namespace std;

void printMap(const map<int, pair<float, float>> &coordinates) {
  for (const auto &entry : coordinates) {
    cout << "Key: " << entry.first << " -> Value: (" << entry.second.first
         << ", " << entry.second.second << ")" << endl;
  }
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "path_coordination");

  RobotCommander my_robot;

  map<int, pair<float, float>> coordinates;

  for (int i = 0; i < 4; ++i) {

    my_robot.move_forward(2); // Move forward for 2 seconds
    my_robot.stop_moving();

    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();

    coordinates.insert(pair<int, pair<float, float>>(i, {x, y}));

    my_robot.turn(1.57, 1); // Turn 90 degrees
    my_robot.stop_moving();
  }

  printMap(coordinates);

  for (int i = 5; i < 9; ++i) {
    my_robot.move_backwards(2); // Move forward for 2 seconds
    my_robot.stop_moving();

    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();

    coordinates.insert(pair<int, pair<float, float>>(i, {x, y}));

    my_robot.turn(1.57, 1); // Turn 90 degrees
    my_robot.stop_moving();
  }

  printMap(coordinates);

  return 0;
}

// Make the robot trace a polygonal path (of your choice).
// Use the methods move_forward(int time) to move forward for n seconds and
// move_backward(int time) to move backwards for n seconds. Use the method
// turn(float velocity_value, int n_secs) to turn the robot. Specify the
// velocity (in rad/s) with velocity_value and the duration of the turn with
// n_secs. Use the method stop_moving() for stopping the robot. Store the (X,Y)
// coordinates of the vertex of the plygon traced in a map. Use the methods
// get_x_position() and get_y_position() to get the current coordinates. Each
// vertex will be stored using an integer key (starting from 1 and increasing in
// 1). (first_vertex) -> 1 (second_vertex) -> 2 (third_vertex) -> 3 and so on...