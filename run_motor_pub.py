#!/usr/bin/env python
# -*- coding: utf-8 -*-
####################################################################
# 프로그램명 : hough_drive.py
# 작 성 자 : 자이트론
#사용법
#1.터미널에서 아두이노 실행
#2.퍼블리셔 실행
#3.rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600    (rosserial 실행)
#4.sudo chmod 666 /dev/ttyACM0     (아두이노 연결 오류 시)
####################################################################
#python으로 아두이노를 제어하기 위한 퍼블리셔
import rospy
import time
from std_msgs.msg import String
from std_msgs.msg import Float64
from pyduino.msg import Drive
#float 64형의 경우에는 하위 데이터 data가 있음 
pub=None   #퍼블리셔 선언 

#퍼블리싱되는 토픽 이름:your_topic
#데이터를 퍼블리싱하는 부분
def drive(angle,speed):
      global pub
      msg = Drive()
      msg.angle = angle
      msg.speed = speed
      print("steering_angle:",msg.angle,"car_speed",msg.speed)
      pub.publish(msg)
      
def talker():
      global pub
      pub = rospy.Publisher('motor_topic',Drive,queue_size=10)
      rospy.init_node('run_motor_pub', anonymous = True)
      rate = rospy.Rate(10) #default is 10hz
      while not rospy.is_shutdown():
	    
	    drive(30,250)
	    #time.sleep(0.5)
	    #drive(90,0)
            rate.sleep()


if __name__=='__main__':
      try:
            talker()
      except rospy.ROSInterruptException:
            pass



