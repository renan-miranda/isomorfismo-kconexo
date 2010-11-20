k-conexo: k-conexo.c lib_kcon.o fila.o
	gcc -g -o k-conexo k-conexo.c lib_kcon.o fila.o

lib_kcon.o: lib_kcon.c lib_kcon.h
	gcc -g -o lib_kcon.o -c lib_kcon.c
fila.o: fila.c fila.h
	gcc -g -o fila.o -c fila.c
