CC = gcc
CFLAGS = -std=c99 -fopenmp
DEPS = functions
TARGET = lab3

$(TARGET): $(TARGET).c
	@$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).c $(DEPS).c -lm
	
run:
	@./$(TARGET).exe

clean:
	@rm -f $(TARGET).exe $(TARGET).o $(DEPS).o

help:
	@echo 'Usage: make [options] [target] ...'
	@echo 'Available targets: '
	@echo '	run		- Runs compiled application'
	@echo '	clean		- Remove generated files'
