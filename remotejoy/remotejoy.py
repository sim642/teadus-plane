from serial import Serial
import uinput

serial = Serial("/dev/ttyUSB0")

events = (
    uinput.ABS_X + (0, 255, 0, 0),
    uinput.ABS_Y + (0, 255, 0, 0),
    uinput.ABS_Z + (0, 255, 0, 0),
    uinput.ABS_THROTTLE + (0, 255, 0, 0),
)

with uinput.Device(events, name="TeadusPlane Remote") as device:
    while True:
        serial.read_until(b"a")
        buf = serial.read(11)

        x = int(buf[0:2], base=16)
        y = int(buf[2:4], base=16)
        z = int(buf[4:6], base=16)
        w = int(buf[6:8], base=16)
        print(x, y, z, w)

        device.emit(uinput.ABS_X, x, syn=False)
        device.emit(uinput.ABS_Y, y, syn=False)
        device.emit(uinput.ABS_Z, z, syn=False)
        device.emit(uinput.ABS_THROTTLE, w)


