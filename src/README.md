# ROS packages 

### walker_control 
Configures and launches the controllers for the walker. The gains of the joint controllers can be changed here. New controllers can be defined here.

### walker_description
Contains the description (urdf) and the meshes for the robot. As well as all physical parameters like joint friction, mass of bodies etc.

### walker_gazebo
Contains files for launching the walker in gazebo (includes walker_control and walker_description). New gazebo worlds can be defiend here.
