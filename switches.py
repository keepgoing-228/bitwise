def to_binary(n, bits=8):
    return format(n & 0xFF, "08b")


switches = 0

while True:
    print(f"now state of switches: {to_binary(switches)}")
    print("1: toggle a switch")
    print("2: check a switch")
    print("3: all on")
    print("4: all off")
    print("5: exit")
    choice = int(input("choose an option: "))

    if choice == 1:
        k = int(input("enter the switch position (0-7): "))
        switches ^= 1 << k  # use XOR to toggle the state
        # switches = switches ^ (1 << k)
    elif choice == 2:
        k = int(input("enter the switch position (0-7): "))
        print("on" if switches & (1 << k) else "off")
    elif choice == 3:
        switches = 0xFF  # 11111111
    elif choice == 4:
        switches = 0  # 00000000
    elif choice == 5:
        break
