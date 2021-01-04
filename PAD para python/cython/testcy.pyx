cpdef long int test(long int number):
    cdef long int i
    cdef long int res = 0

    for i in range(number):
        res += i

    return res