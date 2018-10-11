#include "ros/ros.h"
#include "std_msgs/String.h"

ros::Publisher pub;

void callback(const std_msgs::String::ConstPtr& msg)
{
   pub.publish(msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "post1");

  ros::NodeHandle n;
  pub = n.advertise<std_msgs::String>("chatter2", 1000);

  ros::Subscriber sub = n.subscribe("chatter1", 1000, callback);
   
  ros::spin();

  return 0;
}