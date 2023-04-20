PROGRAMS=cipher testlcg
CFLAGS= -Wall -ansi -pedantic -std=c99

all: $(PROGRAMS)

cipher: cipher.c lcg.c lcg.h 
	gcc $(CFLAGS) -o cipher cipher.c lcg.c -lm

testlcg: testlcg.c lcg.c lcg.h 
	gcc $(CFLAGS) -o testlcg testlcg.c lcg.c -lm

clean:
	-rm $(PROGRAMS)
