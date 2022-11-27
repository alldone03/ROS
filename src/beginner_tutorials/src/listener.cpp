#include <bits/stdc++.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "std_msgs/Int64.h"

void callback1(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void callback2(const beginner_tutorials::Num::ConstPtr &msg)
{
    ROS_INFO("I heard: [%ld]", msg->Num);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe("chatter1", 1000, callback1);
    // ros::Subscriber sub2 = nh.subscribe("chatter2", 1000, callback2);

    ros::spin(); //buat untu subscibe loop

    return 0;
}