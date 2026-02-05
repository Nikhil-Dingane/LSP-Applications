CC = gcc

app: Main.o Helper.o
	$(CC) -o Main Main.o Helper.o

Main.o:
	$(CC) -c Main.c

Helper.o:
	$(CC) -c Helper.c

clean:
	rm -rf *.o
	find . -type f -executable -delete

run:
	./Main
