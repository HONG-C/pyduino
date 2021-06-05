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
  
}

ros::Subscriber<std_msgs::Float64> s("your_topic", &messageCb);


void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(s);
  Serial.begin(57600);
}

void loop()
{
  if(test.data==11.23)
  {
    Serial.println("ok");
  }
  else
  {
    Serial.println("not ok");
    //Serial.println(test.data);
  }
  nh.spinOnce();
  //delay(60);
}
