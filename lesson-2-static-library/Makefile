CC=g++
CFLAGS=-O2 -W -Wall -pedantic
LIBS=

MATH_UTILS_OBJECT_FILES=math.o utils.o program_options.o
MATH_UTILS_SOURCE_FILES=math.cpp utils.cpp program_options.cpp
MATH_UTILS_STATIC_LIB_FILE=mathutils.a

MAIN_OBJECT_FILES=main.o ${MATH_UTILS_STATIC_LIB_FILE}
MAIN_SOURCE_FILES=main.cpp ${MATH_UTILS_STATIC_LIB_FILE}

APP_NAME=math

program: ${MAIN_OBJECT_FILES}
	${CC} ${CFLAGS} ${LIBS} -c ${MAIN_OBJECT_FILES}
	${CC} ${MAIN_OBJECT_FILES} -o ${APP_NAME} 

mathutils.a: ${MATH_UTILS_SOURCE_FILES}
	${CC} ${CFLAGS} ${LIBS} -c ${MATH_UTILS_SOURCE_FILES}
	ar rcs ${MATH_UTILS_STATIC_LIB_FILE} ${MATH_UTILS_OBJECT_FILES}
	ranlib ${MATH_UTILS_STATIC_LIB_FILE}

clean:
	@echo "cleaning the cache";
	rm ${MATH_UTILS_STATIC_LIB_FILE} *.o ${APP_NAME} 