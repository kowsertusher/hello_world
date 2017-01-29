li  = [0] *5001
li[0] = 0
li[1] = 1

for i in range(2,5001):
    li[i] = li[i-1] + li[i-2]

while True:
    try:
        n = input()
        t = int(n)
        print("The Fibonacci number for",t,"is",li[t])
    except:
        break

