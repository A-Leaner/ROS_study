#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char **argv)
{
  //��ʼ��ROS��������ӳ�䣨Ψһ��������Ϊbase name������/
  ros::init(argc, argv, "talker"); 
  // Ϊ���̵Ľڵ㴴��һ���������һ��������NodeHandle��ʼ���ڵ�
  ros::NodeHandle n;
  // ��������Ҫ��chatter topic�Ϸ���һ��std_msgs��Ϣ
  // �����ᶩ������chatter topic�ڵ㣬������ʾ�������еĴ�С���Ƚ��ȳ���
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);  // ��ѭ��Ƶ��
  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    // ������������prinf/cout
    ROS_INFO("%s", msg.data.c_str()); 
    chatter_pub.publish(msg);

    ros::spinOnce();
    // ���ߣ���ʹ����Ƶ��Ϊ10Hz
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
