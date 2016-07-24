from serial import Serial
import pygame
import time

serial = Serial("/dev/ttyUSB0")

pygame.display.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

while True:
    pygame.event.get()

    x = int(joystick.get_axis(0) * 127 + 127)
    y = int(joystick.get_axis(1) * 127 + 127)
    z = int(joystick.get_axis(3) * 127 + 127)
    w = int(joystick.get_axis(2) * 127 + 127)

    print x, y, z, w
    serial.write("a%02x%02x%02x%02x---" % (x, y, z, w))

    time.sleep(0.05)

