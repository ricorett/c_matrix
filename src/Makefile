
# LFLAGS = -lpthread -lcheck -lm
LFLAGS=-L. -ls21_matrix  -lm  -lcheck
#CFLAGS=-Wall -Wextra -pedantic -std=c11

# CFLAGS = -Wall -Wextra -g -O0 --coverage
#LDFLAGS = --coverage

GCOV_FLAGS=--coverage -lgcov  -L/opt/homebrew/opt/lcov
# GCOV_FLAGS=--html --html-details -o gcov_report/index.html
# GCOV_FLAGS=-lgcov --coverage
CC=gcc

SOURCES = $(wildcard ./funcs/*.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean all rebuild

all: s21_matrix.a test

test: libs21_matrix.a tests.o
	$(CC) $(OBJECTS) $^ $(LFLAGS) -o $@
# gcov_report: libs21_matrix.a tests.c
# 		lcov --directory . --zerocounters
# 		./gcov_test
# 		lcov --capture --directory . --output-file coverage.info 
# 		lcov --remove coverage.info '/usr/*' --output-file coverage.info 
# 		genhtml coverage.info --output-directory coverage_report 

gcov_report: $(SOURCES) libs21_matrix.a tests.c
	$(CC) $(CFLAGS) $^ -o gcov_test $(LFLAGS) --coverage
	./gcov_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
#	 gcovr $(GCOV_FLAGS)
	rm -f gcov_test

# gcov_report: libs21_matrix.a tests.c
# 	$(CC) $(CFLAGS) $^  $(LFLAGS) $(GCOV_FLAGS)
# 	./gcov_test
# 	lcov --capture --directory . --output-file coverage.info
# 	genhtml coverage.info --output-directory gcov_report

s21_matrix.a: $(OBJECTS) #s21_matrix.h
	ar -rcs $@ $^

libs21_matrix.a: s21_matrix.a
	cp s21_matrix.a libs21_matrix.a


tests.o: tests.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.gcno *.o ./funcs/*.o test gcov_report *.gcda  coverage.info *.a a.out

rebuild: clean all