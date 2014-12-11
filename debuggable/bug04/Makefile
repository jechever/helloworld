CC = gcc
CFLAGS = -Wall -g 
INCLUDE = -lm -I include
OBJECTS = padding.o scramble.o layers.o
EXE = fft


all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(EXE).c -o $(EXE) 

padding.o: 
	$(CC) $(CFLAGS) -c padding.c  

scramble.o: 
	$(CC) $(CFLAGS) -c scramble.c 

layers.o: 
	$(CC) $(CFLAGS) -c layers.c 

clean : 
	rm -rf $(EXE) *.o
