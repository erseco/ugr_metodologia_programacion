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
all: clean $(BIN)/ejercicio_07 $(BIN)/ejercicio_08 $(BIN)/ejercicio_09 $(BIN)/ejercicio_10_text2bin $(BIN)/ejercicio_10_bin2text $(BIN)/ejercicio_12 $(BIN)/ejercicio_13 $(BIN)/pintabin

# COMPILACION

$(BIN)/ejercicio_07 : $(SRC)/ejercicio_07.cpp
	g++ -o $(BIN)/ejercicio_07 $(SRC)/ejercicio_07.cpp 

$(BIN)/ejercicio_08 : $(SRC)/ejercicio_08.cpp
	g++ -o $(BIN)/ejercicio_08 $(SRC)/ejercicio_08.cpp 

$(BIN)/ejercicio_09 : $(SRC)/ejercicio_09.cpp
	g++ -o $(BIN)/ejercicio_09 $(SRC)/ejercicio_09.cpp 

$(BIN)/ejercicio_10_text2bin : $(SRC)/ejercicio_10_text2bin.cpp
	g++ -o $(BIN)/ejercicio_10_text2bin $(SRC)/ejercicio_10_text2bin.cpp 

$(BIN)/ejercicio_10_bin2text : $(SRC)/ejercicio_10_bin2text.cpp
	g++ -o $(BIN)/ejercicio_10_bin2text $(SRC)/ejercicio_10_bin2text.cpp 

$(BIN)/ejercicio_12 : $(SRC)/ejercicio_12.cpp
	g++ -o $(BIN)/ejercicio_12 $(SRC)/ejercicio_12.cpp 

$(BIN)/ejercicio_13 : $(SRC)/ejercicio_13.cpp
	g++ -o $(BIN)/ejercicio_13 $(SRC)/ejercicio_13.cpp 

$(BIN)/pintabin : $(SRC)/pintabin.cpp
	g++ -o $(BIN)/pintabin $(SRC)/pintabin.cpp 


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
