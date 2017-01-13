CXXFLAGS =	-O2 -fopenmp -g -Wall -fmessage-length=0

OBJS =		comments_translator.o translator.o

LIBS =

TARGET =	bin/translate

$(TARGET):	$(OBJS)
	$(CXX) -fopenmp -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
