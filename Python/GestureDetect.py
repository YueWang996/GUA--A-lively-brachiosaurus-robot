################################################################################
# Copyright (C) 2012 Leap Motion, Inc. All rights reserved.                    #
# NOTICE: This developer release of Leap Motion, Inc. software is confidential #
# and intended for very limited distribution. Parties using this software must #
# accept the SDK Agreement prior to obtaining this software and related tools. #
# This software is subject to copyright.                                       #
################################################################################

import Leap
import sys
import serial
import time

arduino = serial.Serial('COM5', 9600, timeout=.1)
time.sleep(5)


class SampleListener(Leap.Listener):
    def __init__(self):
        super().__init__()
        
    def on_init(self, controller):
        print("Initialized")

    def on_connect(self, controller):
        print("Connected")

    def on_disconnect(self, controller):
        print("Disconnected")

    def on_exit(self, controller):
        print("Exited")

    def on_frame(self, controller):
        # Get the most recent frame and report some basic information
        frame = controller.frame()
        if frame.id % 1 == 0:
            hands = frame.hands
            numHands = len(hands)
            print("Frame id: %d, timestamp: %d, hands: %d, fingers: %d, tools: %d" % (
                frame.id, frame.timestamp, numHands, len(frame.fingers), len(frame.tools)))
            arduino.write(b'\0')
            time.sleep(0.1)

            if numHands >= 1:
                # Get the first hand
                hand = hands[0]

                # Check if the hand has any fingers
                fingers = hand.fingers
                numFingers = len(fingers)
                if numFingers >= 1:
                    
                    # Calculate the hand's average finger tip position
                    pos = Leap.Vector()
                    for finger in fingers:
                        pos += finger.tip_position
            
                    pos = pos.__div__(numFingers)

                    #print("Hand has", numFingers, "fingers with average tip position", pos)

                # Get the palm position
                palm = hand.palm_position
                #print("Palm position:", palm)

                # Get the palm normal vector  and direction
                normal = hand.palm_normal
                direction = hand.direction

                # Calculate the hand's pitch, roll, and yaw angles
                print("Pitch: %f degrees,  Roll: %f degrees,  Yaw: %f degrees" % (
                    direction.pitch * Leap.RAD_TO_DEG,
                    normal.roll * Leap.RAD_TO_DEG,
                    direction.yaw * Leap.RAD_TO_DEG))
                serialData = str(int(direction.pitch * Leap.RAD_TO_DEG))+ '/' + str(int(normal.roll * Leap.RAD_TO_DEG)) +'\n'
                l = list(serialData)
                for x in l:
                    print(x)
                    arduino.write(x.encode())
                    time.sleep(0.1)
                
                
                #print("Hand curvature radius: %f mm" % hand.sphere_radius)


def main():
    # Create a sample listener and controller
    listener = SampleListener()
    controller = Leap.Controller()

    # Have the sample listener receive events from the controller
    controller.add_listener(listener)

    # Keep this process running until Enter is pressed
    print("Press Enter to quit...")
    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass

    # Remove the sample listener when done
    controller.remove_listener(listener)


if __name__ == "__main__":
    main()
