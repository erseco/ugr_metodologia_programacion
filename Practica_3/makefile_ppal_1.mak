# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2012-2013
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_ppal_1.mak
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(BIN)/ppal_1 


$(BIN)/ppal_1 : $(OBJ)/ppal_1.o $(OBJ)/opers.o
	g++ -o $(BIN)/ppal_1 $(OBJ)/ppal_1.o $(OBJ)/opers.o


$(OBJ)/ppal_1.o : $(SRC)/ppal_1.cpp $(INCLUDE)/opers.h
	g++ -c -o $(OBJ)/ppal_1.o $(SRC)/ppal_1.cpp -I$(INCLUDE)


$(OBJ)/opers.o : $(SRC)/opers.cpp $(INCLUDE)/opers.h
	g++ -c -o $(OBJ)/opers.o $(SRC)/opers.cpp -I$(INCLUDE)


# LIMPEZA
  
clean : 
	rm -f $(BIN)/ppal_1 $(OBJ)/ppal_1.o $(OBJ)/opers.o  
