a = 0b1010
b = 0b1100

print(f"a: {a:04b}")
print(f"b: {b:04b}")
print("--------------------------------")

# basic properties
print("basic properties")
print(f"a ^ a: {a ^ a:04b}")  # 0
print(f"a ^ 0: {a ^ 0:04b}")  # a it cancels out

print("XOR is commutative")
print(f"a ^ b ^ a: {a ^ b ^ a:04b}")  # b
print(f"a ^ b ^ b: {a ^ b ^ b:04b}")  # a
print("--------------------------------")


# swap a and b without using a temp variable
print("XOR swap a and b")
a = a ^ b
b = a ^ b  # b changes to original a
a = a ^ b  # a changes to original b

print(f"a: {a:04b}")
print(f"b: {b:04b}")
print("--------------------------------")

# find the number that appears only once in an array
print("find the number that appears only once in an array")
nums = [4, 1, 2, 1, 2]
result = 0
for num in nums:
    result ^= num
print(f"the number that appears only once is: {result}")
print("--------------------------------")


# check if a number is a power of 2
print("check if a number is a power of 2")


def is_power_of_2(n):
    return n > 0 and (n & (n - 1)) == 0


print(f"8 is a power of 2: {is_power_of_2(8)}")
print(f"7 is a power of 2: {is_power_of_2(7)}")
print("--------------------------------")
