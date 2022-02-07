// 
// Version 1.0
// 

// Variables generales
argv = params
ascii = ["", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", " ", "!", "''", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", ""]	

// Comprueba que el input sea el correcto

if (argv.len < 1 or argv.len > 2) then 
	print("\n\nUsage: brainfk [path/to/file.bf] [args]\n")
	exit(null)
else if argv[0] == "-h" or argv[0] == "--help" then
	print("\n\nRead the README.md for more info.\n")
	exit(null)
end if

// Estimacion del inicio del bucle
loop = function(src, pos)
	endLoop = 0
	while 1
		pos = pos - 1
		item = src[pos]
		if item == "]" then
			endLoop = endLoop + 1
		else if item == "[" and endLoop != 0 then
			endLoop = endLoop - 1
		else if item == "[" and endLoop == 0 then
			break
		end if
	end while
	return pos
end function

// Busca errores, como bucles incompletos
checkErrors = function(src, argv)
	lpStat = 0
	clStat = 0
	getInp = 0
	err = 0
	for i in src 
		if i == "[" then
			lpStat = lpStat + 1
		else if i == "]" then
			lpStat = lpStat - 1
		else if i == ">" then
			clStat = clStat + 1
		else if i == "<" then
			clStat = clStat - 1
		else if i == "," then
			getInp = getInp + 1
		end if
	end for
	
	if lpStat != 0 then
		err = err + 1
	end if
	
	if clStat < 0 then
		err = err + 2
	end if
	
	if err != 0 then
		print("Code returned ", err)
		exit(null)
	end if
end function

// Calcula el numero de celdas necesario para que 
// el programa funcione con suficiente espacio + 2
getCells = function(src)
	num = 0
	cells = 0
	for i in source
		if i == ">" then
			num = num + 1
		else if i == "<" then
			num = num - 1
		end if
		if num > cells then
			cells = num
		end if
	end for
	return cells + 2 
end function

// Le das un numero y, con suerte, devolvera su valor ascii
chr = function(num, ascii)
	return ascii[num]
end function

// Le das un ascii y, con suerte, devolvera su valor numerico
ord = function(char, ascii)
	for i in range(ascii.len - 1)
		if ascii[i] == char then
			break
		end if
	end for
	return i
end function

// Hace seguir las reglas de brainfuck de forma estricta
bRules = function(cells, cPos)
	if cells[cPos] > 255 then
		cells[cPos] = 0
	else if cells[cPos] < 0 then
		cells[cPos] = 255
	end if
	return cells[cPos]
end function

// Obtiene el codigo fuente del archivo
file = get_shell.host_computer.File(argv[0])
if file == null then
	print("\n\nFile not found\n")
	exit(null)
else
	source = file.get_content
	print("\nSource code:\n" + source)
end if
	
// Obtiene el input y se lo mete a 'stdin'
if argv.len == 2 then
	stdin = argv[1]
	print("\nArguments: " + stdin)
end if

// Final de output del codigo fuente / argumentos
print("\n\n")

// Busca errores en el codigo
checkErrors(source, argv)

// Agrega el espacio necesario a 'cells' para funcionar
cells = []
for i in range(getCells(source) + 2)
	cells = cells + [0]
end for

// Variables del interpretador
prgPos = 0
cellPos = 0
pArg = 0

// Esto es especifico para GreyScript, 
// ya que no se puede hacer print("stuff", end="")
stdout = ""

// Interpretador
while prgPos != source.len
	
	obj = source[prgPos]
	
	cells[cellPos] = bRules(cells, cellPos)
	
	if obj == ">" then
		cellPos = cellPos + 1
		
	else if obj == "<" then
		cellPos = cellPos - 1
		
	else if obj == "+" then
		cells[cellPos] = cells[cellPos] + 1
		
	else if obj == "-" then
		cells[cellPos] = cells[cellPos] - 1
		
	else if obj == "." then
		stdout = stdout + chr(cells[cellPos], ascii)
		
	else if obj == "," then
		cells[cellPos] = ord(stdin[pArg], ascii)
		pArg = pArg + 1
		
	else if obj == "]" then
		if cells[cellPos] != 0 then
			prgPos = loop(source, prgPos)
		end if
		
	end if
	
	prgPos = prgPos + 1
end while

// Gracias miniscript
print(stdout)

// Final
print("\n\nCode returned 0")
exit(null)
