#include "ros/ros.h"
#include <bits/stdc++.h>
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "std_msgs/Int64.h"
#include <sstream>
// using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<std_msgs::String>("chatter1", 1000);
    ros::Publisher pub2 = nh.advertise<beginner_tutorials::Num>("chatter2", 1000);

    ros::Rate loop_rate(1); //satuan herts

    static int count = 0;

    while (ros::ok())
    {
        std_msgs::String msg;
        beginner_tutorials::Num data;

        std::stringstream ss;
        ss << "hello world "  << count;
        msg.data = ss.str();

        data.Num = 10;

        ROS_INFO("%s", msg.data.c_str());
        // ROS_INFO("%ld", data.Num);

        pub1.publish(msg);
        pub2.publish(data);

        ros::spinOnce(); 

        loop_rate.sleep(); //delay satuan hertz

        ++count;
    }
}