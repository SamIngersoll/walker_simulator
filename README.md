## Robot Simulator

Make sure you have ros neotic and ros-control installed.

Then make sure you source ros `/opt/ros/noetic/setup.bash`

first run `catkin_make` from the `walker_simulator` directory, then `source devel/setup.bash`
then you can run the simulator with `roslaunch walker_gazebo walker_world.launch`

you can then write a message to the controllers to test if the robot is working with `rostopic pub /walker/right_hip_position_controller/command std_msgs/Float64 "data: 1.0"`, you should see the robot twitch.
