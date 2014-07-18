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
all: clean 	$(BIN)/ejercicio1 $(BIN)/ejercicio2 $(BIN)/ejercicio3 $(BIN)/ejercicio4 $(BIN)/ejercicio5 $(BIN)/ejercicio6 $(BIN)/ejercicio7 $(BIN)/ejercicio8 $(BIN)/ejercicio9 $(BIN)/ejercicio10 $(BIN)/ejercicio11 $(BIN)/ejercicio12 $(BIN)/ejercicio13 $(BIN)/ejercicio_6_1 $(BIN)/ejercicio_6_2 $(BIN)/ejercicio_6_3

# COMPILACION

$(BIN)/ejercicio1 : $(SRC)/ejercicio1.cpp
	g++ -o $(BIN)/ejercicio1 $(SRC)/ejercicio1.cpp 

$(BIN)/ejercicio2 : $(SRC)/ejercicio2.cpp
	g++ -o $(BIN)/ejercicio2 $(SRC)/ejercicio2.cpp 

$(BIN)/ejercicio3 : $(SRC)/ejercicio3.cpp
	g++ -o $(BIN)/ejercicio3 $(SRC)/ejercicio3.cpp 

$(BIN)/ejercicio4 : $(SRC)/ejercicio4.cpp
	g++ -o $(BIN)/ejercicio4 $(SRC)/ejercicio4.cpp 

$(BIN)/ejercicio5 : $(SRC)/ejercicio5.cpp
	g++ -o $(BIN)/ejercicio5 $(SRC)/ejercicio5.cpp 

$(BIN)/ejercicio6 : $(SRC)/ejercicio6.cpp
	g++ -o $(BIN)/ejercicio6 $(SRC)/ejercicio6.cpp 

$(BIN)/ejercicio7 : $(SRC)/ejercicio7.cpp
	g++ -o $(BIN)/ejercicio7 $(SRC)/ejercicio7.cpp 

$(BIN)/ejercicio8 : $(SRC)/ejercicio8.cpp
	g++ -o $(BIN)/ejercicio8 $(SRC)/ejercicio8.cpp 

$(BIN)/ejercicio9 : $(SRC)/ejercicio9.cpp $(OBJ)/Pila.o 
	g++ -o $(BIN)/ejercicio9 $(SRC)/ejercicio9.cpp $(OBJ)/Pila.o -I$(INCLUDE)

$(OBJ)/Pila.o : $(SRC)/Pila.cpp
	g++ -c -o $(OBJ)/Pila.o $(SRC)/Pila.cpp -I$(INCLUDE)

$(BIN)/ejercicio10 : $(SRC)/ejercicio10.cpp
	g++ -o $(BIN)/ejercicio10 $(SRC)/ejercicio10.cpp 

$(BIN)/ejercicio11 : $(SRC)/ejercicio11.cpp
	g++ -o $(BIN)/ejercicio11 $(SRC)/ejercicio11.cpp 

$(BIN)/ejercicio12 : $(SRC)/ejercicio12.cpp
	g++ -o $(BIN)/ejercicio12 $(SRC)/ejercicio12.cpp 

$(BIN)/ejercicio13 : $(SRC)/ejercicio13.cpp
	g++ -o $(BIN)/ejercicio13 $(SRC)/ejercicio13.cpp 

$(BIN)/ejercicio_6_1 : $(SRC)/ejercicio_6_1.cpp
	g++ -o $(BIN)/ejercicio_6_1 $(SRC)/ejercicio_6_1.cpp 

$(BIN)/ejercicio_6_2 : $(SRC)/ejercicio_6_2.cpp
	g++ -o $(BIN)/ejercicio_6_2 $(SRC)/ejercicio_6_2.cpp 

$(BIN)/ejercicio_6_3 : $(SRC)/ejercicio_6_3.cpp $(OBJ)/Lista.o 
	g++ -o $(BIN)/ejercicio_6_3 $(SRC)/ejercicio_6_3.cpp $(OBJ)/Lista.o -I$(INCLUDE)

$(OBJ)/Lista.o : $(SRC)/Lista.cpp
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)


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
