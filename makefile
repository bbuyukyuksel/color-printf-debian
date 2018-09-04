define setColor
	@tput setaf $1
endef

define resetColor	
      @tput sgr0
endef

MKDIR_P = mkdir -p
OUT_DIR = lib obj 
.PHONY: directories

all: directories main

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}


IDIR=include
ODIR=obj
LDIR=lib
SDIR=src

CC=gcc

#CFLAGS is about INCLUDE directory. 
CFLAGS=-I$(IDIR)

LIBS=-lm

_DEPS = cprintf.h
_OBJ = main.o cprintf.o 

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(call setColor,9)
		$(CC) -c -o $@ $< $(CFLAGS)
	$(call setColor,50)	
		#$< [$(SDIR)/%.c] dizini içerisindeki elemanları tek tek indexler.
main: $(OBJ)
	
	$(call setColor,50)
		#$(CC) -o $(SDIR)/$(@).out $^ $(CFLAGS) $(LIBS)
	$(call setColor,9)
		$(CC) -o $(@).out $^ $(CFLAGS) $(LIBS)
	$(call setColor,50)	
		#$@ main adını tutar.
		#$^ OBJ listesindeki elemanları tutar.
	$(call setColor,60)
		@echo "\n->main.out dosyası başarı ile oluşturuldu."
compile: $(OBJ)
	$(call setColor,3)
		ar rc $(LDIR)/libcprintf.a $^
		ranlib $(LDIR)/libcprintf.a
	$(call setColor,60)
		@echo "\n->Kütüphane dosyaları derlendi."
clean:
	$(call setColor,1)
		rm -rf $(ODIR) $(SDIR)/*.out $(LDIR) *.out
	$(call setColor, 60)	
		@echo "\n->Temizleme işlemi bitti."