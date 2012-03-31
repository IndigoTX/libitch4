OUTPUT = itch_parser_test
OBJECTS = itch_parser_test.o

CPPFLAGS += -I../src -std=c++0x -stdlib=libc++
LDFLAGS += -L../src
LDLIBS += -litch4 -stdlib=libc++
.PHONY : all
all : $(OUTPUT)

itch_parser_test : itch_parser_test.o

itch_parser_test.o : itch_parser_test.cc

itch_parser_test.cc : ../src/itch_parser.hh ../src/itch_buffer.hh message_dispatcher.hh

.PHONY : clean
clean :
	-rm $(OUTPUT) $(OBJECTS)
