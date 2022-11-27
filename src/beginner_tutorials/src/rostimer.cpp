#include "ros/ros.h"
#include "bits/stdc++.h"

    using namespace ros;

void callback1(const TimerEvent &event)
{
    ROS_INFO("Callback 1 triggered");
}

void callback2(const TimerEvent &event)
{
    ROS_INFO("Callback 2 triggered");
}

int main(int argc, char **argv)
{
    init(argc, argv, "rostimer");
    NodeHandle nh;

    Timer timer1 = nh.createTimer(Duration(0.1), callback1);
    Timer timer2 = nh.createTimer(Duration(1), callback2);

    spin();

    return 0;
}