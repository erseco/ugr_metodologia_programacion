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
all: clean $(BIN)/ejercicio7_1 $(BIN)/ejercicio7_2 $(BIN)/ejercicio8 $(BIN)/ejercicio9

# COMPILACION
$(BIN)/ejercicio7_1 : $(OBJ)/VectorDinamico.o
	g++ -o $(BIN)/ejercicio7_1 $(SRC)/ejercicio7_1.cpp $(OBJ)/VectorDinamico.o -I$(INCLUDE)

$(BIN)/ejercicio7_2 : $(OBJ)/VectorDinamico.o
	g++ -o $(BIN)/ejercicio7_2 $(SRC)/ejercicio7_2.cpp $(OBJ)/VectorDinamico.o -I$(INCLUDE)

$(OBJ)/VectorDinamico.o : $(SRC)/VectorDinamico.cpp
	g++ -c -o $(OBJ)/VectorDinamico.o $(SRC)/VectorDinamico.cpp -I$(INCLUDE)


$(BIN)/ejercicio8 : $(OBJ)/Matriz2D_1.o 
	g++ -o $(BIN)/ejercicio8 $(SRC)/ejercicio8.cpp $(OBJ)/Matriz2D_1.o -I$(INCLUDE)

$(BIN)/ejercicio9 : $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/ejercicio9 $(SRC)/ejercicio9.cpp $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o -I$(INCLUDE)



$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_2.o : $(SRC)/Matriz2D_2.cpp
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)



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
