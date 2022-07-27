import sys

def gcd(a, b):
    for i in range(min(a, b), 0, -1):
        if (a % i == 0 and b % i == 0):
             return (i)

#최소공배수 = 두 수의 곱 / 최대공약수
def lcm(a, b):
    g = gcd(a, b)
    return ((a * b) // g)

num = list(map(int, sys.stdin.readline().split()))
print(lcm(num[0], num[1]))
