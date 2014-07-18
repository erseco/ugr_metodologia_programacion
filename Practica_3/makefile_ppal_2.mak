# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2012-2013
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_ppal_2.mak
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(BIN)/ppal_2 


$(BIN)/ppal_2 : $(OBJ)/ppal_2.o $(OBJ)/adicion.o $(OBJ)/producto.o
	g++ -o $(BIN)/ppal_2 $(OBJ)/ppal_2.o $(OBJ)/adicion.o $(OBJ)/producto.o


$(OBJ)/ppal_2.o : $(SRC)/ppal_2.cpp $(INCLUDE)/adicion.h $(INCLUDE)/producto.h
	g++ -c -o $(OBJ)/ppal_2.o $(SRC)/ppal_2.cpp -I$(INCLUDE)


$(OBJ)/adicion.o : $(SRC)/adicion.cpp $(INCLUDE)/adicion.h
	g++ -c -o $(OBJ)/adicion.o $(SRC)/adicion.cpp -I$(INCLUDE)


$(OBJ)/producto.o : $(SRC)/producto.cpp $(INCLUDE)/producto.h
	g++ -c -o $(OBJ)/producto.o $(SRC)/producto.cpp -I$(INCLUDE)
 

# LIMPEZA
 
clean : 
	rm -f $(BIN)/ppal_2 $(OBJ)/ppal_2.o $(OBJ)/adicion.o $(OBJ)/producto.o
 
