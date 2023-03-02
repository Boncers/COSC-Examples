#A really cool way to find a factorial with recursion
def factorial(num):
    if num == 1:
        return 1
    else:
        return num * factorial(num - 1)
print(factorial(4))
#4! == 24
