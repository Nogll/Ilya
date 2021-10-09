n = int(input())
a = input()
b = input()
  
def f(a, b):
  c = ""
  for i in range(len(a)):
    if a[i] == b[i]:
      c += '0'
    else:
      c += '1'
  return c

ans = f(a, b)

cnt = 0

for i in ans:
  if i == '0': cnt += 1
  else: break
  
print(ans[cnt:])