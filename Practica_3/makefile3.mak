# Fichero: makefil3.mak 
# Construye el ejecutable "saludo" a partir de "saludo.cpp" 
# Tambien puede construirse el objeto "saludo.o" a partir de "saludo.cpp"

SRC = ./src
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
LIB = ./lib


all: $(BIN)/saludo

all: clean obj/saludo.o bin/saludo


bin/saludo : src/saludo.cpp
	@echo Creando saludo...
	g++ src/saludo.cpp -o bin/saludo

# Esta regla especifica un destino que no es un fichero ejecutable.

obj/saludo.o : src/saludo.cpp
	@echo Creando saludo.o solamente...
	g++ -c src/saludo.cpp -o obj/saludo.o

.PHONY : clean
clean:
	-rm obj/*
	@echo Carpeta obj limpia
