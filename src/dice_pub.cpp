#include <ros/ros.h>
#include <diceroller/My2Dice.h>

int main (int argc, char **argv) {
	ros::init(argc, argv, "dice_pub");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<diceroller::My2Dice>("/dicedata", 10);

	double pub_freq = 1; // defualt is 1 Hz
	nh.getParam("/dice_pub_freq", pub_freq);
	ros::Rate rate(pub_freq);  
	
	while (ros::ok()) {
		diceroller::My2Dice dice;
		dice.d1 = rand()%6+1;
        	dice.d2 = rand()%6+1;;
		pub.publish(dice);
		rate.sleep();
	}
}
