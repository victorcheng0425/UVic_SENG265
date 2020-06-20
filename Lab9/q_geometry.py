#!/usr/bin/env python3
import math

'''
        POINT CLASS

        class attributes: x and y

        ** Write a constructor. You may write more than 1 if you want to

        ** Write function __repr__

        ** Write function delta_x
            Arguments: d
            Purpose: Creates and return a new point with class attributes x+d and y

        ** Write function delta_y
            Arguments: d
            Purpose: Creates and return a new point with class attributes x and y+d

        ** Write function translate
            Arguments: dx and dy
            Purpose: Creates and returns a new point with class attributes x+dx and y+dx

'''
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def __repr__(self):
        return "Point({}, {})".format(self.x, self.y)

    def delta_x(self, x):
        return Point(self.x + x, self.y)

    def delta_y(self, y):
        return Point(self.x, self.y + y)

    def translate(self, x, y):
        return Point(self.x + x, self.y + y)

"""
p1 = Point()
p2 = Point(2,3)
p1
p2
"""

'''
        CIRCLE CLASS

        class attributes: center and radius
        REMEMBER, the center is a point

        ** Write a constructor. You may write more than 1 if you want to

        ** Write function __repr__

        ** Write function area
            Arguments: YOU DECIDE
            Purpose: calcualtes and returns the area of the circle object

        ** Write function perimeter
            Arguments: YOU DECIDE
            Purpose: calculates and returns the perimeter of the circle object

        ** Write function translate
            Arguments: dx and dy
            Purpose: Creates and returns a new circle object whose center is at the point obtained
            by modifiying the center of this object's center by dx and dy

'''
class Circle:

    def __init__(self, x, y):
        self.point = x
        self.y = y

    def translate(self, x, y):
        return Circle(self.point.translate(x, y), self.y)

    def perimeter(self):
        return self.y*2*math.pi

    def area(self):
        return math.pi*(self.y)**2
    def __repr__(self):
        return "Circle({}, {})".format(self.point, self.y)

'''
        SQUARE CLASS

        class attributes: 2 points representing a diagonal of a square
        REMEMBER, the center is a point

        ** Write a constructor. You may write more than 1 if you want to

        ** Write function __repr__

        ** Write function area
            Arguments: YOU DECIDE
            Purpose: calcualtes and returns the area of the square object

        ** Write function perimeter
            Arguments: YOU DECIDE
            Purpose: calculates and returns the perimeter of the square object

        ** Write function translate
            Arguments: dx and dy
            Purpose: Creates and returns a new square object the attribute points of which are
            obtained by modifying the attribute points each of this object by dx and dy

'''

class Square:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def perimeter(self):
        return (abs(self.x.x - self.y.x) + abs(self.x.y - self.y.y))*2

    def area(self):
        return (abs(self.x.x - self.y.x) * abs(self.x.y - self.y.y))

    def translate(self, x , y):
        return Square(self.x.translate(x, y), self.y.translate(x, y))

    def __repr__(self):
        return "Square({}, {})".format(self.x, self.y)

class Tri:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def __repr__(self):
        return "Tri({},{})".format(self.x, self.y)

    def perimeter(self):
        return 123

    def area(self):
        return self.x*self.y/2

