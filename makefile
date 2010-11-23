all: k-conexo isomorfos

k-conexo: k-conexo.c lib_kcon.o fila.o
	gcc -g -o k-conexo k-conexo.c lib_kcon.o fila.o

lib_kcon.o: lib_kcon.c lib_kcon.h
	gcc -g -o lib_kcon.o -c lib_kcon.c

fila.o: fila.c fila.h
	gcc -g -o fila.o -c fila.c

isomorfos: isomorfos.c lib_iso.o lib_matriz.o lib_ord.o
	gcc -g -o isomorfos isomorfos.c lib_iso.o lib_matriz.o lib_ord.o

lib_iso.o: lib_iso.c lib_iso.h
	gcc -g -o lib_iso.o -c lib_iso.c

lib_matriz.o: lib_matriz.c lib_matriz.h
	gcc -g -o lib_matriz.o -c lib_matriz.c

lib_ord.o: lib_ord.c lib_ord.h
	gcc -g -o lib_ord.o -c lib_ord.c

clean: clean-iso clean-kcon

clean-iso:
	rm -rf lib_iso.o lib_matriz.o lib_ord.o
	rm -rf isomorfos

clean-kcon:
