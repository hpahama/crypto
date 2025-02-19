from itertools import count
N = count()
make_z = lambda n : n // 2 if n % 2 else -n // 2
Z = (make_z(n) for n in count(1))
# We can see elements of these infinite collections with
[next(N) for _ in range(5)], [next(Z) for _ in range(5)] 
