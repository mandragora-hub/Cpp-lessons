CC=g++
CFLAGS=-O2 -W -Wall -pedantic
LIBS=

LIB_VERSION=1.1.1
LIB_NAME=libSimpleEncoder.so


create_shared_lib: simple_encoder.cpp
	${CC} -fPIC -c simple_encoder.cpp
	${CC} -shared  simple_encoder.o -o ${LIB_NAME}.${LIB_VERSION}
	

clean:
	@echo "cleaning the cache";
	rm simple_encoder.o ${LIB_NAME}.${LIB_VERSION}