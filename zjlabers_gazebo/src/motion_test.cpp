#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv)
{
	// ROS节点初始化
	ros::init(argc, argv, "motion_publisher");
	
	// 创建节点句柄
	ros::NodeHandle n;
	
	// 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
	ros::Publisher motion_1_pub = n.advertise<std_msgs::Float64>("/zjlabers_sim/head_pitch_position_controller/command", 1);
    ros::Publisher motion_2_pub = n.advertise<std_msgs::Float64>("/zjlabers_sim/neck_yaw_position_controller/command", 1);
    
	// 设置循环的频率
	ros::Rate loop_rate(10);


    int count = 0;
    
	while (ros::ok())
	{
	    count ++;
	    
		std_msgs::Float64 motion_1;
		std_msgs::Float64 motion_2;
		
		motion_1.data = count*10.0/180*3.1415;
		motion_2.data = count*10.0/180*3.1415;

	    // 发布消息
		motion_1_pub.publish(motion_1);
		motion_2_pub.publish(motion_2);
		
//		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
//				vel_msg.linear.x, vel_msg.angular.z);

	    // 按照循环频率延时
	    loop_rate.sleep();
	}

	return 0;
}
