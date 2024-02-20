CC=g++
CFLAGS=-O2 -W -Wall -pedantic
LIBS=-lSDL

OBJECT_FILES=*.o
SOURCE_FILES=*.cpp

APP_NAME=appname


program: ${SOURCE_FILES}
	${CC} ${CFLAGS} ${LIBS} -c ${SOURCE_FILES}
	${CC} ${OBJECT_FILES} -o ${APP_NAME} 


clean:
	@echo "cleaning the cache";
	rm ${OBJECT_FILES} ${APP_NAME} 