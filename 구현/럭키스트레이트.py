n = str(input())

div = len(n)//2

front = n[:div]
back = n[div:]

result1 = 0
result2 = 0
for i in range(div):
  result1 += int(front[i])
  result2 += int(back[i])

if result1 == result2:
  print("LUCKY")
else: print("READY")