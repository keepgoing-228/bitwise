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

if __name__ == "__main__":
    basic(5, 3)
    # shift()
    # print(to_binary(-5))
    # print(binary_to_decimal("0b101"))
    # print(binary_to_decimal(to_binary(-5)))