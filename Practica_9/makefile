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
all: clean $(BIN)/ejercicio1 $(BIN)/ejercicio2 $(BIN)/ejercicio3 $(BIN)/ejercicio4 $(BIN)/ejercicio5 $(BIN)/ejercicio6 $(BIN)/ejercicio7

# COMPILACION

$(BIN)/ejercicio1 : $(OBJ)/MiVectorDinamico.o 
	g++ -o $(BIN)/ejercicio1 $(SRC)/ejercicio1.cpp $(OBJ)/MiVectorDinamico.o -I$(INCLUDE)

$(OBJ)/MiVectorDinamico.o : $(SRC)/MiVectorDinamico.cpp
	g++ -c -o $(OBJ)/MiVectorDinamico.o $(SRC)/MiVectorDinamico.cpp -I$(INCLUDE)


$(BIN)/ejercicio2 : $(OBJ)/Matriz2D_1.o 
	g++ -o $(BIN)/ejercicio2 $(SRC)/ejercicio2.cpp $(OBJ)/Matriz2D_1.o -I$(INCLUDE)

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(BIN)/ejercicio3 : $(OBJ)/Matriz2D_2.o 
	g++ -o $(BIN)/ejercicio3 $(SRC)/ejercicio3.cpp $(OBJ)/Matriz2D_2.o -I$(INCLUDE)

$(OBJ)/Matriz2D_2.o : $(SRC)/Matriz2D_2.cpp
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)

$(BIN)/ejercicio4 : $(OBJ)/Lista.o 
	g++ -o $(BIN)/ejercicio4 $(SRC)/ejercicio4.cpp $(OBJ)/Lista.o -I$(INCLUDE)

$(OBJ)/Lista.o : $(SRC)/Lista.cpp
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)

$(BIN)/ejercicio5 : $(OBJ)/Pila.o 
	g++ -o $(BIN)/ejercicio5 $(SRC)/ejercicio5.cpp $(OBJ)/Pila.o -I$(INCLUDE)

$(OBJ)/Pila.o : $(SRC)/Pila.cpp
	g++ -c -o $(OBJ)/Pila.o $(SRC)/Pila.cpp -I$(INCLUDE)

$(BIN)/ejercicio6 : $(OBJ)/Cola.o 
	g++ -o $(BIN)/ejercicio6 $(SRC)/ejercicio6.cpp $(OBJ)/Cola.o -I$(INCLUDE)

$(OBJ)/Cola.o : $(SRC)/Cola.cpp
	g++ -c -o $(OBJ)/Cola.o $(SRC)/Cola.cpp -I$(INCLUDE)

$(BIN)/ejercicio7 : $(OBJ)/Conjunto.o 
	g++ -o $(BIN)/ejercicio7 $(SRC)/ejercicio7.cpp $(OBJ)/Conjunto.o -I$(INCLUDE)

$(OBJ)/Conjunto.o : $(SRC)/Conjunto.cpp
	g++ -c -o $(OBJ)/Conjunto.o $(SRC)/Conjunto.cpp -I$(INCLUDE)


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
