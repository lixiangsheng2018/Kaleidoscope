CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		toy.o

LIBS =

TARGET =	Kaleidoscope

CXX = clang++


$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
