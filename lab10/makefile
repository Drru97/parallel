CC = mpicc
CFLAGS = -std=c99 -fopenmp
DEPS = functions
TARGET = lab10
RUN_ARGS = -np
NUM_THREADS = 4

$(TARGET): $(TARGET).c
	@$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).c $(DEPS).c
	
run:
	@mpirun $(RUN_ARGS) $(NUM_THREADS) $(TARGET).exe

clean:
	@rm -f $(TARGET).exe $(TARGET).o $(DEPS).o

help:
	@echo 'Usage: make [options] [target] ...'
	@echo 'Available targets: '
	@echo '	run		- Runs compiled application'
	@echo '	clean		- Remove generated files'
