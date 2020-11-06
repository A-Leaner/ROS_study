#include "ros/ros.h"
#include "std_msgs/String.h"
// �ص�����
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  // ����master��Ҫ����chatter topic��Ϣ
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin(); // ��ѭ��
  return 0;
}
