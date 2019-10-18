OBJECTS : calmain.o add.o sub.o mul.o div.o
CC = gcc
CFLAGS = -g -O2
TARGET = calculation

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(TARGET) $(OBJECTS)
