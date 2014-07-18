# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2012-2013
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_1lib_4mod.mak
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(LIB)/libopers_4mod.a $(BIN)/ppal_1lib_4mod 


$(BIN)/ppal_1lib_4mod : $(OBJ)/ppal.o $(LIB)/libopers_4mod.a
	g++ -o $(BIN)/ppal_1lib_4mod $(OBJ)/ppal.o -lopers_4mod -L$(LIB)


$(OBJ)/ppal.o : $(SRC)/ppal.cpp $(INCLUDE)/opers_4mod.h
	g++ -c -o $(OBJ)/ppal.o $(SRC)/ppal.cpp -I$(INCLUDE)


# CONSTRUCCION DE LA BIBLIOTECA

$(LIB)/libopers_4mod.a : $(OBJ)/suma.o $(OBJ)/resta.o $(OBJ)/multiplica.o $(OBJ)/divide.o
	ar -rvs $(LIB)/libopers_4mod.a $(OBJ)/suma.o $(OBJ)/resta.o \
                                       $(OBJ)/multiplica.o $(OBJ)/divide.o

$(OBJ)/suma.o : $(SRC)/suma.cpp 
	g++ -c -o $(OBJ)/suma.o $(SRC)/suma.cpp 

$(OBJ)/resta.o : $(SRC)/resta.cpp 
	g++ -c -o $(OBJ)/resta.o $(SRC)/resta.cpp 

$(OBJ)/multiplica.o : $(SRC)/multiplica.cpp 
	g++ -c -o $(OBJ)/multiplica.o $(SRC)/multiplica.cpp 

$(OBJ)/divide.o : $(SRC)/divide.cpp 
	g++ -c -o $(OBJ)/divide.o $(SRC)/divide.cpp 


# LIMPEZA

clean : 
	rm $(LIB)/libopers_4mod.a\ 
           $(BIN)/ppal_1lib_4mod $(OBJ)/ppal.o\
           $(OBJ)/suma.o $(OBJ)/resta.o $(OBJ)/multiplica.o $(OBJ)/divide.o
 
