#!/usr/bin/env python
# -*- coding: utf-8 -*-

#python으로 아두이노를 제어하기 위한 퍼블리셔
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64

#퍼블리싱되는 토픽 이름:your_topic

#데이터를 퍼블리싱하는 부분
def talker():
      pub = rospy.Publisher('your_topic',Float64,queue_size=10)
      rospy.init_node('py_talker', anonymous = True)
      rate = rospy.Rate(60) #60hz,default is 10hz
      while not rospy.is_shutdown():
	    test_val=1.234
            rospy.loginfo(test_val)
            pub.publish(test_val)
            rate.sleep()

if __name__=='__main__':
      try:
            talker()
      except rospy.ROSInterruptException:
            pass



