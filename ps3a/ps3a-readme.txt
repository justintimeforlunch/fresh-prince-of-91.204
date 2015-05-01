/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Justin Nguyen
OS: Linux
Machine (e.g., Dell Latitude, MacBook Pro): Asus
Text editor: Emacs
Hours to complete assignment (optional): 23

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
The Body object (celestial) uses SFML to to draw each celestrial object through the draw() function that we had to change to work with our project.

We also had to overload the >> operator, which takes isteam and sets them to variables to be outputted using
  in >> x_pos >> y_pos >> x_vel >> y_vel >> i_mass
which takes in the numbers from the txt file that was given to us.

The universe also scales itself depending on the background image (or any other size we give it).

Uses vectors to input as many planets as we want too seen from
     std::vector<Body> planets;

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Asked Professor Grinberg about how < planet.txt worked, and what variables I needed.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Couldn't figure out how to input everything from planet.txt.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
n/a
