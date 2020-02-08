#include <ros/ros.h>
#include <diceroller/My2Dice.h>

void callback_rcv_topic(const diceroller::My2Dice& d) 
{
	ROS_INFO_STREAM("dice1 = " << (int)d.d1 << "   dice2 = " << (int)d.d2);
}

int main (int argc, char **argv) 
{
	ros::init(argc, argv, "dice_sub");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("/dicedata", 1000, callback_rcv_topic);
	ros::spin();
}
