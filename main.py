'''
Version en python del interpretador de brainfuck, 
para tener una idea general a la hora de portearlo 
a C.
'''

# Libreria necesaria para los argumentos.
from sys import *
argc = len(argv)

# Comprueba que los argumentos sean correctos
if argc < 2 or argc > 3:
    print(f"\n\nUsage: {argv[0]} [path/to/file.bf] [args]\n")
    exit(1)

# Devuelve una estimacion del inicio del bucle
def loop(src, pos):
    endLoop = 0
    while 1:
        pos -= 1
        item = src[pos]
        if item == "]":
            endLoop += 1
        elif item == "[" and endLoop != 0:
            endLoop -= 1
        elif item == "[" and endLoop == 0:
            break
    return pos

# Busca errores, como bucles incompletos.
def checkErrors(source, argv):
    lpStat = clStat = getInp = err = 0
    for i in source:
        if i == "[":
            lpStat += 1
        elif i == "]":
            lpStat -= 1
        elif i == ">":
            clStat += 1
        elif i == "<":
            clStat -= 1
        elif i == ",":
            getInp += 1

    if lpStat != 0:
        err += 1

    if clStat < 0:
        err += 2
        
    if len(argv) < 3 and getInp != 0:
        err += 4
    try:
        if len(argv[2]) < getInp:
            err += 4
    except:
        pass
    
    if err != 0:
        print(f"\nCode returned {err}.")
        exit(err)


# Calcula el numero necesario de celdas 
# para que el programa funcione correctamente 
# usando el minimo numero de recursos.
def getCells(source):
    num = cells = 0
    for i in source:
        if i == ">":
            num += 1
        elif i == "<":
            num -= 1
        if num > cells:
            cells = num
    return cells + 2


# Obtiene el input y se lo mete a 'stdin'
if len(argv) == 3:
    stdin = argv[2]
    print(f"\nArgumentos: {stdin}")

# Leer el codigo del archivo.
with open(argv[1], "r") as file:
    source = file.read()
    print(f"\nCodigo fuente:\n{source}\n\n")

# Comprueba que no hayan errores es el codigo.
checkErrors(source, argv)

# Variables del interpretador.
prgPos = cellPos = pArg = 0

# Le agrega el numero necesario de celdas necesarias + 2, 
# para situaciones inesperadas
cells = []
for i in range(getCells(source)):
    cells.append(0)


# Interpretador.
while prgPos != len(source):
    # Le da el valor de la instruccion a 'obj' 
    # para mayor facilidad de acceso.
    obj = source[prgPos]

    # TODO: Un def para seguir de forma estricta las reglas de brainfuck
    
    # Comportamiento segun el valor de la instruccion.
    if obj == ">":
        cellPos += 1

    elif obj == "<":
        cellPos -= 1
    
    elif obj == "+":
        cells[cellPos] += 1
    
    elif obj == "-":
        cells[cellPos] -= 1
    
    elif obj == ".":
        print(chr(cells[cellPos]), end="")
    
    elif obj == ",":
        cells[cellPos] = ord(stdin[pArg])
        pArg += 1
    
    elif obj == "]":
        if cells[cellPos] != 0:
            prgPos = loop(source, prgPos)

    # Pasa a la siguiente instruccion.
    prgPos += 1 

print("\n\nCode returned 0")
exit(0)
