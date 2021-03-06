// this program publishes commands to joint controllers
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h> // For rand() and RAND_MAX
#include <string.h>
#include <vector>

#include "read_trajectory.h"




// DOES NOT CORRECTLY LOAD FILE
// MAYBE MAKE CONTROLLER A SEPARATE C++ SCRIPT (NOT BUILT WITH WALKER_CONTROL) SO THE PATH SHIT IS EASIER

const std :: string joints[6] = {"left_hip", "left_carriage", "left_leg", "right_hip", "right_carriage", "right_leg"};


int main ( int argc, char ** argv ) {
    using namespace std;

    // if random is true, robot moves joints randomly, else tries to run a trajectory
    bool random = false;

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

    int index = 0;
    int enddex = 0;
    vector<vector<double>> trajectory;
    if (!random) {
        // read trajectory from csv file
                            
        string filename = "/home/sam/walker_simulator/src/walker_control/src/trajectories/trajectory.csv";
        int result = read_trajectory( trajectory, filename);
        if (result) return 1;
        enddex = trajectory.size();
    }

    // loop at 2Hz until the node is shut down.
    ros :: Rate rate(2) ;
    while ( ros :: ok() ) {
        // create and fill in the message.

        for (int i=0 ; i<6 ; i++) {
            if (random) {
                messages[i].data = 2 * double ( rand () ) /double(RAND_MAX) - 1; 
            } else {
                if (index < enddex) {
                    messages[i].data = trajectory[index][i]; 
                } else {
                    // index = 0;
                    return 0;
                }
            }
            // publish the message.
            publishers[i].publish (messages[i]);
        }
        index++;

        // wait until it 's time for another iteration.
        rate.sleep() ;
    }


}




