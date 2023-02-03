str = str(input())
div = len(str)//2

front = str[:div]
back = str[div:]

f = 0
b = 0
for i in range(div):
  f += int(front[i])
  b += int(back[i])

if f == b:
  print("LUCKY")
else: print("READY")