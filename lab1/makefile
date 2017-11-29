CC = gcc
CFLAGS = -std=c99 -fopenmp
TARGET = lab1

$(TARGET): $(TARGET).c
	@$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).c
	
run:
	@./$(TARGET).exe

clean:
	@rm -f $(TARGET).exe $(TARGET).o

help:
	@echo 'Usage: make [options] [target] ...'
	@echo 'Available targets: '
	@echo '	run		- Runs compiled application'
	@echo '	clean		- Remove generated files'
