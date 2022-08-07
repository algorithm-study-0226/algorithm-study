t = int(input())


def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


for i in range(t):
    n = int(input())

    n1, n2 = n // 2, n // 2

    while True:
        if isPrime(n1) and isPrime(n2):
            print(f"{n1} {n2}")
            break

        n1 -= 1
        n2 += 1
