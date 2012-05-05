.PHONY: all install

CPPFLAGS:=-std=c++11

PROGRAM:=tabule

all: $(PROGRAM)

$(PROGRAM): src/main.o src/parse_args.o src/crunch.o src/utf8.o
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

install: $(PROGRAM)
	install -D -m 755 $< $(PREFIX)/usr/bin/$<

clean:
	rm -vf src/*.o

mrproper: clean
	rm -vf $(PROGRAM)
