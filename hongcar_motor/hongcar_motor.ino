/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */

#include <ros.h>
#include <std_msgs/Float64.h>
#include <Drive.h>
#include <Servo.h>//include servo headerfile

Servo servo;//using Servo class, make servo object


//To communicate with ros system,setting an nodehandle
ros::NodeHandle nh;



pyduino::Drive test;//make message
void messageCb(const pyduino::Drive& msg)
{
  test.angle = msg.angle;
  test.speed = msg.speed;
}


ros::Subscriber<pyduino::Drive> s("your_topic", &messageCb);


void setup()
{
  //motorA
  pinMode(12, OUTPUT);//cw,ccw
  pinMode(9, OUTPUT);//brake
  //motorB
  pinMode(13, OUTPUT);//cw,ccw
  pinMode(8, OUTPUT);//brake
  servo.attach(7);
  nh.initNode();
  nh.subscribe(s);
  Serial.begin(57600);
}

void loop()
{
  
  Serial.println(test.speed);//check topic
  Serial.println(test.angle);//check topic
  digitalWrite(12,1);
  digitalWrite(9,0);
  analogWrite(3,test.speed);
  digitalWrite(13,0);
  digitalWrite(8,0);
  analogWrite(11,test.speed);
  servo.write(test.angle);
  delay(100);
  nh.spinOnce();
  
  delay(60);
}
