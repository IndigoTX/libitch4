export CXXFLAGS = -ggdb3 -std=c++0x -W -Wall -Wextra -pedantic
SUBDIRS = src tests

.PHONY : subdirs $(SUBDIRS)

subdirs : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@

tests : src

.PHONY : clean
clean :
	for dir in $(SUBDIRS); do \
	  $(MAKE) -C $$dir clean; \
	done

