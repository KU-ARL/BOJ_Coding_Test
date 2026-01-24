N = int(input(""))

a = list(map(str, input().split()))


while True :
    exc = ''.join(str(s) for s in a)
    if int(exc) == 0:
        a = ['0']
        break

    x = N
    for i in range(N - 1):
        if int(a[i] + a[i+1]) < int(a[i+1] + a[i]):
            a[i], a[i+1] = a[i+1], a[i]
            x -= 1

    if x == N:
        break




result = ''.join(str(s) for s in a)
print(result)