# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2012-2013
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_1lib_2mod.mak
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(LIB)/libopers_2mod.a $(BIN)/ppal_1lib_2mod 


$(BIN)/ppal_1lib_2mod : $(OBJ)/ppal.o $(LIB)/libopers_2mod.a
	g++ -o $(BIN)/ppal_1lib_2mod $(OBJ)/ppal.o -lopers_2mod -L$(LIB)


$(OBJ)/ppal.o : $(SRC)/ppal.cpp $(INCLUDE)/opers_2mod.h
	g++ -c -o $(OBJ)/ppal.o $(SRC)/ppal.cpp -I$(INCLUDE)


# CONSTRUCCION DE LA BIBLIOTECA

$(LIB)/libopers_2mod.a : $(OBJ)/adicion.o $(OBJ)/producto.o
	ar -rvs $(LIB)/libopers_2mod.a $(OBJ)/adicion.o $(OBJ)/producto.o

$(OBJ)/adicion.o : $(SRC)/adicion.cpp $(INCLUDE)/adicion.h
	g++ -c -o $(OBJ)/adicion.o $(SRC)/adicion.cpp -I$(INCLUDE)

$(OBJ)/producto.o : $(SRC)/producto.cpp $(INCLUDE)/producto.h
	g++ -c -o $(OBJ)/producto.o $(SRC)/producto.cpp -I$(INCLUDE)

# LIMPEZA

clean : 
	@rm -f $(LIB)/libopers_2mod.a\
        $(BIN)/ppal_1lib_2mod $(OBJ)/ppal.o\
        $(OBJ)/adicion.o $(OBJ)/producto.o   
