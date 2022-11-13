CC=g++
CFLAGS=-fPIC
INC=-I./inc
LIBDIR=./lib
LIBS=-lencoder
BIN=bin/encoder

all: create_directories $(BIN)

create_directories:
	@echo create directories ...    
	@mkdir -p lib bin inc obj src	

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

shared: lib/libencoder.so
	$(eval CFLAGS += -Wl,-rpath=$(LIBDIR))

static: lib/libencoder.a
	$(eval CFLAGS += -static)

lib/libencoder.so: obj/encoding.o obj/decoding.o
	$(CC) $(CFLAGS) -shared $^ -o $@

lib/libencoder.a: obj/encoding.o obj/decoding.o
	ar cvq $@ $^

$(BIN): shared obj/main.o
	$(CC) $(CFLAGS) obj/main.o -L$(LIBDIR) $(LIBS) -o $@
 
clean:	
	@echo cleaning directories ...  
	@rm -rf lib bin obj 
