# Fichero: makefile2.mak
# Construye el ejecutable saludo a partir de saludo.cpp

bin/saludo : obj/saludo.o

	g++ obj/saludo.o -o bin/saludo


obj/saludo.o : src/saludo.cpp

	g++ -c src/saludo.cpp -o obj/saludo.o


