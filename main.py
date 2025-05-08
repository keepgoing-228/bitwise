def basic(a, b):
    print(f"a = {a},     binary = {to_binary(a)}")
    print(f"b = {b},     binary = {to_binary(b)}")
    print("--------------------------------")

    print(f"a & b = {a & b}, binary = {to_binary(a & b)}")
    print(f"a | b = {a | b}, binary = {to_binary(a | b)}")
    print(f"a ^ b = {a ^ b}, binary = {to_binary(a ^ b)}")
    print(f"~a = {~a},   binary = {to_binary(~a)}") # result of two's complement: ~a = -a - 1

def shift():
    print(5 << 1)
    print(5 >> 1)

def to_binary(n) -> str:
    # return format(n & 0xFF, '08b') # 0xFF is the mask to get the last 8 bits
    return bin(n)

def binary_to_decimal(n) -> int:
    return int(n, 2)

def is_even(n) -> bool:
    return n & 1 == 0

if __name__ == "__main__":
    # basic(5, 3)
    # shift()
    # print(to_binary(-5))
    # print(binary_to_decimal("0b101"))
    # print(binary_to_decimal(to_binary(-5)))

    ## check if a number is even or odd
    # print(is_even(2))
    # print(is_even(3))

    ## check the k-th bit of a number
    # n = int(input("Enter a number: "))
    # k = int(input("Enter the bit position you want to check: "))
    # if n & (1 << k) != 0:
    #     print(f"The {k}-th bit of {n} is 1")
    # else:
    #     print(f"The {k}-th bit of {n} is 0")

    ## check number of 1 bits in a number: leetcode 191
    n = int(input("Enter a number: "))
    count = 0
    while n:
        count += n & 1
        n = n >> 1
    print(count)

