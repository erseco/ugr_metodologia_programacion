# 
# Metodología de la Programación
# Grado en Ingeniería Informática
# 
# 2014 - Ernesto Serrano Collado
#

# VARIABLES
BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

# TODO (sin empaquetado)
all: clean $(BIN)/ejercicio1 $(BIN)/ejercicio2 $(BIN)/ejercicio3 $(BIN)/ejercicio4 $(BIN)/ejercicio5 $(BIN)/ejercicio6

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
