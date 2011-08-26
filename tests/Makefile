OUTPUT = itch_parser_test
OBJECTS = itch_parser_test.o

CPPFLAGS += -I../src
LDFLAGS += -L../src
LDLIBS += -litch4
CC = g++

.PHONY : all
all : $(OUTPUT)

itch_parser_test : itch_parser_test.o

itch_parser_test.o : itch_parser_test.cc

itch_parser_test.cc : ../src/itch_parser.hh ../src/itch_buffer.hh

.PHONY : clean
clean :
	-rm $(OUTPUT) $(OBJECTS)