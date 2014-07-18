# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2013-2014
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile para ilustrar el uso de g++ y las opciones habituales 
# en su ejecución, ficheros de cabecera, bibliotecas, ...
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(LIB)/libutils.a $(BIN)/demo 


$(BIN)/demo : $(OBJ)/demo.o $(LIB)/libutils.a
	g++ -o $(BIN)/demo $(OBJ)/demo.o -lutils -L$(LIB)


$(OBJ)/demo.o : $(SRC)/demo.cpp $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/demo.o $(SRC)/demo.cpp -I$(INCLUDE)


# CONSTRUCCION DE LA BIBLIOTECA

$(LIB)/libutils.a : $(OBJ)/utils.o
	ar -rvs $(LIB)/libutils.a $(OBJ)/utils.o

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/utils.o $(SRC)/utils.cpp -I$(INCLUDE)

  
# LIMPEZA

clean : 
	-rm $(LIB)/libutils.a $(BIN)/demo $(OBJ)/demo.o $(OBJ)/utils.o   
