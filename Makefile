all:
	gcc -O3 -c Rijndael-EK.c -o Rijndael-EK.o
	ar rcs libRijndael-EK.a Rijndael-EK.o
check:
	gcc -static -O3 check.c -o check -L. -lRijndael-EK
	./check
