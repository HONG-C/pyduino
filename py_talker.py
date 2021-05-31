#!/usr/bin/env python
# -*- coding: utf-8 -*-

#python으로 아두이노를 제어하기 위한 퍼블리셔
import rospy
import random
from std_msgs.msg import String

def talker():
      pub = rospy.Publisher('toggle_led',String,queue_size=10)
      rospy.init_node('py_talker', anonymous = True)
      rate = rospy.Rate(10) #10hz
      while not rospy.is_shutdown():
	    test_val="Published Successfully"
            rospy.loginfo(test_val)
            pub.publish(test_val)
            rate.sleep()

if __name__=='__main__':
      try:
            talker()
      except rospy.ROSInterruptException:
            pass



