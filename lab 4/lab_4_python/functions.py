from equation import *
import random


def initialize():
    n = int(input("plese, input n: "))
    m = int(input("plese, input m: "))
    lst = []
    sum_linear = 0
    sum_squared = 0

    for i in range(n):
        A = Squared(random.randint(- 100, 100), random.randint(-100, 100), random.randint(-100, 100),
                    random.randint(-100, 100))
        lst.append(A)
        if A.solve_equation():
            sum_linear += sum(A.solve_equation())
    for i in range(m):
        A = Linear(random.randint(-100, 100), random.randint(-100, 100), random.randint(-100, 100))
        lst.append(A)
        if A.solve_equation():
            if A.solve_equation() is list:
                sum_squared += sum(A.solve_equation())
            else:
                sum_squared += A.solve_equation()

    return lst, sum_linear, sum_squared

def print_equations(lst, sum_linear, sum_squared):
    i = 0
    for item in lst:
        print(i)
        i += 1
        print(item.print())
        print(item.solve_equation())

    print("sum linear" , str(sum_linear))
    print("sum squared", str(sum_squared))

def checkroot(lst):
    i = int(input("please, input code of equation you want to check"))
    x = int(input("x, please: "))
    result = lst[i].check(x)
    print(lst[i].print())
    print(result)



def do():
    equations = initialize()
    print_equations(equations[0], equations[1], equations[2])
    checkroot(equations[0])

