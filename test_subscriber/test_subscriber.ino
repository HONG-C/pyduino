/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */

#include <ros.h>
#include <std_msgs/Float64.h>


ros::NodeHandle nh;

float x; 

void messageCb( const std_msgs::Float64& msg){
  x = msg.data;
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

std_msgs::Float64 test;
ros::Subscriber<std_msgs::Float64> s("your_topic", &messageCb);


void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(s);
}

void loop()
{
  test.data = x;
  if (sizeof(test.data)==4)
  {
    Serial.println(test.data);
  }
  nh.spinOnce();
  delay(10);
}
