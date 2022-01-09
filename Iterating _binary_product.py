import itertools
n = 5
for i in itertools.product([0, 1], repeat=n): #количество = !n
  print(i)
