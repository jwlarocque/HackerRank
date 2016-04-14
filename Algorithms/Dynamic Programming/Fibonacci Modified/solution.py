def memoize(f):
    cache = {}
    def decorated(*args):
        if args in cache:
            return cache[args]
        else:
            cache[args] = f(*args)
            return cache[args]
    return decorated
    
@memoize # :\ I forgot about this...
def moddedFib(a, b, n):
    if (n == 1):
        return a
    if (n == 2):
        return b
    return (moddedFib(a, b, n - 1) ** 2) + moddedFib(a, b, n - 2)
    
values = raw_input().split(" ")
print moddedFib(int(values[0]), int(values[1]), int(values[2]))