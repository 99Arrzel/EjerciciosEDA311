
print("Hello World")
if 5 > 2:
    print("5 es mayor que 2")
if 5 > 2:
    print("con espacios")
x = 5
y = "hello"
print(y)
# comentar?¿
"""
comentar
"""
x = int(3)
print (type(x))
x,y,z = "Naranja", "Banana", "Cherry"
print (x,y,z)
x = z = y = "Naranja"
print (x,y,z)
frutas = ["Manzana", "Banana", "Cherry"]
x,y,z = frutas #unpacking
print (x,y,z)
x = "XD"
print ("Disney" + x) #imprimir
x = "Python es facilito "
y = "EZ"
z = x + y #concatenar
print (z)
x = 5
y = 10
print (x+y) #suma en print
x = "10"
def myFunc(): #define
    print("Python vale " + x)

myFunc() #ejecuta
def myFunc2():
    global x #declarado global
    x = "Facilitooo" #debe asignarse después el valor
    print ("Python es " + x)
myFunc2()
print("Python es que??? " + x)
z = complex(2, -3)
print(z)
x = 35e3
y = 12E4
z = -87.7e100
x = int(x)
print(type(x))
print(y)
print(z)
import random
print (random.randrange(1,10))
a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""
print(a)
a = "Hello, World!"
print(a[1])
for x in "banana":
  print(x)
a = "Hello, World!"
print(len(a))
txt = "The best things in life are free!"
print("free" not in txt)
a = "Hello, World!"
print(a.upper())
a = " Hello, World! "
print(a.strip())#de principio o final
a = "Hello, World!"
print(a.replace("H", "J"))
a = "Hello, World!"
print(a.split(",")) #, is target
age = 36
txt = "My name is John, and I am {}"
print(txt.format(age))
x = "Hello"
y = 15

print(bool(x))
print(bool(y))
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[:4])
thislist = ["apple", "banana", "cherry"]
thislist.insert(2, "watermelon") #desplaza al 2
print(thislist)
thislist = ["apple", "banana", "cherry"]
tropical = ["mango", "pineapple", "papaya"]
thislist.extend(tropical)#concatena listas 
print(thislist)
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]

newlist = [x for x in fruits if "a" in x]#newlist = [expression for item in iterable if condition == True]

print(newlist)
thislist = ["apple", "banana", "cherry"]
thislist.clear()#limpiar lista
print(thislist)
newlist = [x.upper() for x in newlist]#A mayuscula
print(newlist)
thislist = ["orange", "mango", "kiwi", "pineapple", "banana"]
thislist.sort(reverse = True)
print(thislist)
thislist = ["banana", "Orange", "Kiwi", "cherry"]
thislist.sort(key = str.lower)
thislist.reverse()
print(thislist)
