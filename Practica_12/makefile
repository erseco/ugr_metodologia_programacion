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
all: clean $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_06 $(BIN)/ejercicio_11 $(BIN)/ejercicio_14 $(BIN)/ejercicio_15 $(BIN)/ejercicio_16 

# COMPILACION

$(BIN)/ejercicio_04 : $(SRC)/ejercicio_04.cpp
	g++ -o $(BIN)/ejercicio_04 $(SRC)/ejercicio_04.cpp 

$(BIN)/ejercicio_05 : $(SRC)/ejercicio_05.cpp $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/ejercicio_05 $(SRC)/ejercicio_05.cpp $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o -I$(INCLUDE)

$(BIN)/ejercicio_06 : $(SRC)/ejercicio_06.cpp
	g++ -o $(BIN)/ejercicio_06 $(SRC)/ejercicio_06.cpp 

$(BIN)/ejercicio_11 : $(SRC)/ejercicio_11.cpp
	g++ -o $(BIN)/ejercicio_11 $(SRC)/ejercicio_11.cpp 

$(BIN)/ejercicio_14 : $(SRC)/ejercicio_14.cpp
	g++ -o $(BIN)/ejercicio_14 $(SRC)/ejercicio_14.cpp 

$(BIN)/ejercicio_15 : $(SRC)/ejercicio_15.cpp
	g++ -o $(BIN)/ejercicio_15 $(SRC)/ejercicio_15.cpp 

$(BIN)/ejercicio_16 : $(SRC)/ejercicio_16.cpp
	g++ -o $(BIN)/ejercicio_16 $(SRC)/ejercicio_16.cpp 

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_2.o : $(SRC)/Matriz2D_2.cpp
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)


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
