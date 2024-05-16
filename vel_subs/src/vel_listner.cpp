#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../vel_test/include/vel_test/vel_test.h"

void velCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  float vel_lin = msg-> twist.twist.linear.x;
  float vel_ang = msg-> twist.twist.angular.z;
  ros::Duration(1).sleep();
  display_vel(vel_lin,vel_ang);
  
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "vel_listner");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, velCallback);
  
  ros::spin();

  return 0;
}