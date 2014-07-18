#####################################
# 									#
# Metodología de la Programación	#
# Grado en Ingeniería Informática	#
# 									#
# 2014 - Ernesto Serrano Collado	#
#									#
#####################################

# VARIABLES
BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

# TODO (sin empaquetado)
all: clean $(BIN)/ejercicio09 $(BIN)/ejercicio10

# COMPILACION

$(BIN)/ejercicio09 : $(OBJ)/ConversorMatrices.o $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/ejercicio09 $(SRC)/ejercicio09.cpp $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o $(OBJ)/ConversorMatrices.o -I$(INCLUDE)

$(OBJ)/ConversorMatrices.o : $(SRC)/ConversorMatrices.cpp
	g++ -c -o $(OBJ)/ConversorMatrices.o $(SRC)/ConversorMatrices.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_2.o : $(SRC)/Matriz2D_2.cpp
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)

$(BIN)/ejercicio10 : $(OBJ)/Poligono.o 
	g++ -o $(BIN)/ejercicio10 $(SRC)/ejercicio10.cpp $(OBJ)/Poligono.o -I$(INCLUDE)

$(OBJ)/Poligono.o : $(SRC)/Poligono.cpp
	g++ -c -o $(OBJ)/Poligono.o $(SRC)/Poligono.cpp -I$(INCLUDE)

# EMPAQUETADO
# Genera el archivo .zip de la práctica mediante la linea de comandos
# Omite los archivos propios de MacOSX y coge el nombre del directorio como nombre
.PHONY : package
package : clean
	@echo "Empaquetando..."	
	zip $(shell basename "$(CURDIR)")_Ernesto_Serrano.zip -9 -r ./* -x "*.DS_Store" -x "__MACOSX"

# LIMPEZA
# Limpia los archivos compilados, así como los archivos objeto y los paquetes zip
.PHONY : clean
clean : 
	@echo "Limpiando..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
        ./*.zip
