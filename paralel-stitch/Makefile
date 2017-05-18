CC = mpicc
CFLAGS = `pkg-config opencv --cflags --libs`
TARGET = stitch

all:
	$(CC) -o $(TARGET) $(TARGET).cpp $(CFLAGS)

clean:
	$(RM) $(TARGET)
