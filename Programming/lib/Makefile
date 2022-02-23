CFLAGS = -c -I$(HOME)/Programming/include
OBJS = ../src/fraction.o

libdataStructures.a: $(OBJS)
	ar r libdataStructures.a $(OBJS)
	ranlib libdataStructures.a

../src/fraction.o: ../src/fraction.cc ../include/fraction.h
	g++ $(CFLAGS) -o ../src/fraction.o ../src/fraction.cc

