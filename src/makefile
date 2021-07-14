CC=gcc
CFLAGS=
LIBS= -lncurses

IDIR=../includes
ODIR=./obj
_HEADS = matrix.h display.h
_OBJ = main.o matrix.o display.o

HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
# *.o depends on the .c file of the same name
# '@' is the left of the colon, '<' is the first arg right of ':'
# '^' is the right side of the ':'

$(ODIR)/%.o: %.c $(IDIR)
	$(CC) -c -o $@ $<

executable: $(OBJ)
	$(CC) -o a.out $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR)/*.o ./a.out
