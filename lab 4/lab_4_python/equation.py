from abc import ABC, abstractmethod
import math

class Equation(ABC):
    @abstractmethod
    def __init__(self):
        pass

    @abstractmethod
    def solve_equation(self):
        pass

    @abstractmethod
    def check(self):
        pass

    @abstractmethod
    def print(self):
        pass


class Linear(Equation):
    def __init__(self, a, b, y):
        self.__a = a
        self.__b = b
        self.__y = y

    def solve_equation(self):
        if self.__b == 0:
            return None
        x = (self.__y - self.__a) / self.__b
        return x

    def check(self, x):
        if (self.__a + x * self.__b) == self.__y:
            return "x is root of equation"
        else:
            return "x is not root of equation"

    def print(self):
        text = f'{self.__a} + ({self.__b})*x = {self.__y}'
        return text


class Squared(Equation):
    def __init__(self, a, b, c, y):
        self.__a = a
        self.__b = b
        self.__c = c
        self.__y = y

    def solve_equation(self):
        if self.__b == 0 and self.__c == 0:
            return None
        if self.__c == 0:
            return f'{self.__a} + ({self.__b})*x = {self.__y}'
        disk = self.__b * self.__b - 4 * self.__a * self.__c
        if disk < 0:
            return None
        else:
            x1 = (-1 * self.__b - math.sqrt(disk)) / (2 * self.__a)
            x2 = (-1 * self.__b + math.sqrt(disk)) / (2 * self.__a)
        return x1, x2

    def check(self, x):
        if (self.__a + x * self.__b + self.__c * x * x) == self.__y:
            return "x is root of equation"
        else:
            return "x is not root of equation"

    def print(self):
        text = f'{self.__a} + ({self.__b})*x + ({self.__c})*x^2 = {self.__y}'
        return text

