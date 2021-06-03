/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */

#include <ros.h>
#include <std_msgs/Float64.h>


ros::NodeHandle nh;

std_msgs::Float64 test;
ros::Publisher p("my_topic", &test);

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(p);
  Serial.begin(57600);
}

void loop()
{
  test.data=1.0354;
  p.publish( &test );
  nh.spinOnce();
  delay(10);
}
