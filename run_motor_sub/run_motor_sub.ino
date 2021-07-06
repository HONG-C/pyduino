/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */

#include <ros.h>
#include <std_msgs/Float64.h>


//To communicate with ros system,setting an nodehandle
ros::NodeHandle nh;


std_msgs::Float64 test;
void messageCb( const std_msgs::Float64& msg)
{
  test.data = msg.data;
  
}


ros::Subscriber<std_msgs::Float64> s("your_topic", &messageCb);


void setup()
{
  //motorA
  pinMode(12, OUTPUT);//cw,ccw
  pinMode(3, OUTPUT);//speed
  pinMode(9, OUTPUT);//brake
  //motorB
  pinMode(13, OUTPUT);//cw,ccw
  pinMode(11, OUTPUT);//speed
  pinMode(8, OUTPUT);//brake
  nh.initNode();
  nh.subscribe(s);
  Serial.begin(57600);
}

void loop()
{
  
  if(test.data==250)
  {
    Serial.println("ok");
  }
  else
  {
    Serial.println("not ok");
    Serial.println(test.data);
  }

  digitalWrite(12,1);
  digitalWrite(3,test.data);
  delay(1000);
  
  digitalWrite(13,1);
  digitalWrite(11,test.data);
  delay(1000);
  //function for starting callback function
  //when message is subscribed, start callback function
  nh.spinOnce();
  
  delay(60);
}
