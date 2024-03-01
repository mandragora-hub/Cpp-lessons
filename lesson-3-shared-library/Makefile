CC=g++
CFLAGS=-O2 -W -Wall -pedantic
# LIBS=-L./shared/ -l:libSimpleEncoder.so.1.1.1
LIBS=-lSimpleEncoder

MAIN_OBJECT_FILES=main.o utils.o program_options.o
MAIN_SOURCE_FILES=main.cpp utils.cpp program_options.cpp

APP_NAME=encoder

program: ${MAIN_OBJECT_FILES}
	${CC} ${CFLAGS} -c ${MAIN_OBJECT_FILES}
	${CC} ${MAIN_OBJECT_FILES} ${LIBS} -o ${APP_NAME} 


clean:
	@echo "cleaning the cache";
	rm ${MAIN_OBJECT_FILES} ${APP_NAME} 