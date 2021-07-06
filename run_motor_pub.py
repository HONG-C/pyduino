#!/usr/bin/env python
# -*- coding: utf-8 -*-

#python으로 아두이노를 제어하기 위한 퍼블리셔
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64
#float 64형의 경우에는 하위 데이터 data가 있음 


#퍼블리싱되는 토픽 이름:your_topic
#퍼블리싱하는 노드 이름:py_talker

#데이터를 퍼블리싱하는 부분
def talker():
      pub = rospy.Publisher('your_topic',Float64,queue_size=10)
      rospy.init_node('py_talker', anonymous = True)
      rate = rospy.Rate(10) #default is 10hz
      while not rospy.is_shutdown():
	    test_val=250
            rospy.loginfo(test_val)
            pub.publish(test_val)
            rate.sleep()

if __name__=='__main__':
      try:
            talker()
      except rospy.ROSInterruptException:
            pass



