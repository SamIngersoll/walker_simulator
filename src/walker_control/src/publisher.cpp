// This program publishes randomly−generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs:: Twist
#include <std_msgs/Float64.h>
#include <stdlib.h> // For rand() and RAND_MAX

const char controllers[6] = {"left_hip", "left_carriage", "left_leg", "right_hip", "right_carriage", "right_leg"} 

int main ( int argc , char ** argv ) {
    // Initialize the ROS system and become a node.
    ros :: init( argc, argv, "publish_velocity" ) ;
    ros :: NodeHandle nh ;

    // Create a publisher object.
    ros :: Publisher right_hip_position_publisher = nh.advertise <std_msgs :: Float64 >(
    "walker/right_hip_position_controller/command", 1000);

    // Seed the random number generator.
    srand ( time (0) ) ;

    // Loop at 2Hz until the node is shut down.
    ros :: Rate rate(2) ;
    while ( ros :: ok() ) {
        // Create and fill in the message. The other four
        // fields , which are ignored by turtlesim , default to 0.
        // geometry_msgs :: Twist msg ;
        // msg.linear.x = double ( rand () ) / double(RAND_MAX) ;
        // msg.angular.z = 2 * double ( rand () ) /double(RAND_MAX) - 1;

        std_msgs :: Float64 right_hip_angle_command;
        right_hip_angle_command.data = 2 * double ( rand () ) /double(RAND_MAX) - 1; 
        // Publish the message.
        right_hip_position_publisher.publish (right_hip_angle_command) ;

        // Send a message to rosout with the details .
        // ROS_INFO_STREAM( "Sending random velocity command: "
        // << "linear=" << msg.linear.x
        // << " angular=" << msg.angular.z ) ;

        // Wait until it 's time for another iteration .
        rate.sleep() ;
    }
}