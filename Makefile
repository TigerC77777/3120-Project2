CFLAGS= -Wall -g
FILES= main.cpp
TARGET= main.out

# This variable can be set on the command line, and defines the file name to read from
# readFile=input.txt

build:
	gcc++ $(CFLAGS) $(FILES) -o $(TARGET)
run:
	./$(TARGET)
clean:
	rm -f $(TARGET)