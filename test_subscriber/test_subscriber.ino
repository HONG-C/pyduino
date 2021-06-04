/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */

#include <ros.h>
#include <std_msgs/Float64.h>


ros::NodeHandle nh;

std_msgs::Float64 test;
void messageCb( const std_msgs::Float64& msg){
  test.data = msg.data;
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<std_msgs::Float64> s("your_topic", &messageCb);


void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(s);
}

void loop()
{
  if (sizeof(test.data)==4)
  {
    Serial.println(test.data);
  }
  nh.spinOnce();
  delay(60);
}
