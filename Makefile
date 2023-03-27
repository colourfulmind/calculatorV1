CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
LFLAGS = -fprofile-arcs -ftest-coverage
INC_CHECK = $(shell pkg-config --cflags --libs check)
SOURCES:= ./sources/parserToReversePolish.c ./sources/findResult.c ./sources/optional.c

ifeq ($(OS),Linux)
	CC+=-D LINUX_OS
	LFLAGS+=-lsubunit -lrt -lm -lpthread
else
	ifeq ($(OS),Darwin)
		CC+=-D MAC_OS
		LFLAGS+=-lm -lpthread
	endif
endif

all: calculation.a test gcov_report install

clean:
	rm -rf *.o *.a test *.html coverage_report.css *.out *.gcda *.gcno test.dSYM ./report
	rm -rf ui_*.h moc_* QMakefile qrc_qrc.cpp .qmake.stash

rebuild: clean all

install:
	mkdir app
	qmake -o ./QMakefile mainwindow.pro
	make -f ./QMakefile

uninstall: clean
	rm -rf ./app

dvi:
	open ./docs/html/index.html

dist:
	tar -c -f calculator.tar ./app/calculator.app

test: calculation.a ./sources/test.c
	$(CC) ./sources/test.c $(INC_CHECK) $(CFLAGS) $(LFLAGS) -lcheck calculation.a -o $@

calculation.a: $(SOURCES)
	$(CC) -c $(CFLAGS) --coverage $?
	ar -rcs $@ *.o
	ranlib $@
	rm -f *.o

gcov_report: test
	./$?
	mkdir report
	gcovr -r . --html --html-details -o ./report/coverage_report.html
	rm -f *.gcda *.gcno
	open ./report/coverage_report.html

clang:
	clang-format -i ./sources/*.c* ./headers/*.h
	clang-format -n ./sources/*.c* ./headers/*.h

leak: test
	leaks -atExit -- ./test

valgrind: test
	valgrind --log-file="out_valgrind.txt" --leak-check=full -v ./test

.PHONY: all clean rebuild install uninstall dvi dist test calculation.a gcov_report clang leak valgrind
