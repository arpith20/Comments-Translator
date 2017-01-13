CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		comments_translator.o translator.o

LIBS =

TARGET =	translate

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
