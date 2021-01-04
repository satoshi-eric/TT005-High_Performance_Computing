import timeit

cy = timeit.timeit('testcy.test(10**8)', setup="import testcy", number=1)
py = timeit.timeit('testpy.test(10**8)', setup="import testpy", number=1)

print("Cython: {}s".format(round(cy, 3)))
print("Python: {}s".format(round(py, 3)))
print("Cython is {}x faster".format( round(py/cy, 2) ) )