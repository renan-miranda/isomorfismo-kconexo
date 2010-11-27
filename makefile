ISO=libs_iso
KCON=libs_kcon

all: k-conexo isomorfos

k-conexo: $(KCON)/k-conexo.c $(KCON)/lib_kcon.o $(KCON)/pilha.o
	@gcc -g -o k-conexo $(KCON)/k-conexo.c $(KCON)/*.o

lib_kcon.o: $(KCON)/lib_kcon.c $(KCON)/lib_kcon.h
	@gcc -g -o $(KCON)/lib_kcon.o -c $(KCON)/lib_kcon.c

pilha.o: $(KCON)/fila.c $(KCON)/fila.h
	@gcc -g -o $(KCON)/pilha.o -c $(KCON)/fila.c

isomorfos: $(ISO)/isomorfos.c $(ISO)/lib_iso.o $(ISO)/lib_matriz.o $(ISO)/lib_ord.o $(ISO)/lista.o
	@gcc -g -o isomorfos $(ISO)/isomorfos.c $(ISO)/*.o

lib_iso.o: $(ISO)/lib_iso.c $(ISO)/lib_iso.h
	@gcc -g -o $(ISO)/lib_iso.o -c $(ISO)/lib_iso.c

lib_matriz.o: $(ISO)/lib_matriz.c $(ISO)/lib_matriz.h
	@gcc -g -o $(ISO)/lib_matriz.o -c $(ISO)/lib_matriz.c

lib_ord.o: $(ISO)/lib_ord.c $(ISO)/lib_ord.h
	@gcc -g -o $(ISO)/lib_ord.o -c $(ISO)/lib_ord.c

lista.o: $(ISO)/lista.c $(ISO)/lista.h
	@gcc -g -o $(ISO)/lista.o -c $(ISO)/lista.c

clean: clean-iso clean-kcon

clean-iso:
	@rm -rf $(ISO)/*.o
	@rm -rf isomorfos

clean-kcon:
	@rm -rf $(KCON)/*.o
	@rm -rf k-conexo
