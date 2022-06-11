#!/usr/bin/python3

from smbus import SMBus

addr = 0x8
bus  = SMBus(1)
send = 1

print("Enter 1 for ON or 0 for OFF")
while send == 1:
    led_status = input(">>  ")

    if led_status == "1":
        bus.write_byte(addr, 0x1)
    elif led_status == "0":
        bus.write_byte(addr, 0x0)
    else:
        bus.write_byte(addr, 0x0)
