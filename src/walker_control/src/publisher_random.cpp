// this program publishes commands to joint controllers
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h> // For rand() and RAND_MAX
#include <string.h>

const std :: string joints[6] = {"left_hip", "left_carriage", "left_leg", "right_hip", "right_carriage", "right_leg"};


int main ( int argc , char ** argv ) {
    // initialize the ROS system and become a node.
    ros :: init( argc, argv, "publish_velocity" );
    ros :: NodeHandle nh;

    // array to hold publishers and messages for each joint
    ros :: Publisher publishers[6];
    std_msgs :: Float64 messages[6];

    // create a vector of publisher objects.
    for (int i=0 ; i<6 ; i++) {
        publishers[i] = nh.advertise <std_msgs :: Float64 >("walker/"+joints[i]+"_position_controller/command", 1000);
    }

    // seed the random number generator.
    srand ( time (0) ) ;

    // loop at 2Hz until the node is shut down.
    ros :: Rate rate(2) ;
    while ( ros :: ok() ) {
        // create and fill in the message.

        for (int i=0 ; i<6 ; i++) {
            messages[i].data = 2 * double ( rand () ) /double(RAND_MAX) - 1; 
            // publish the message.
            publishers[i].publish (messages[i]);
        }

        // wait until it 's time for another iteration.
        rate.sleep() ;
    }
}



