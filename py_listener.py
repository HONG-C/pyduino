#!/usr/bin/env python
# -*- coding: utf-8 -*-

#python으로 아두이노를 제어하기 위한 서브스크라이버 
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64

#서브스크라이빙되는 토픽 이름:my_topic

def callback(data):
      rospy.loginfo(rospy.get_caller_id() + "my_topic:%s", data.data)


def listener():
      rospy.init_node('listener',anonymous=True)

      rospy.Subscriber("my_topic", Float64, callback)

      rospy.spin()

if __name__=='__main__':
      listener()


