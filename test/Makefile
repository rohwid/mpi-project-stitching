CC = g++
CFLAGS = `pkg-config opencv --cflags --libs`
TARGET = load-show

all:
	$(CC) -o $(TARGET) $(TARGET).cpp $(CFLAGS)

clean:
	$(RM) $(TARGET)
