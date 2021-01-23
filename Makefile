# Quelldateien
SOURCES := main.c fraktal.c graphic.c dialog.c
# zugehörige Include Dateien
INCLUDES := dialog.h fraktal.h graphic.h
PRECOMPILEDHEADERS := $(INCLUDES:.h=.h.gch)
# aus Quelldateien resultierende Objektdateien
OBJS := $(SOURCES:.c=.o)
# benötigte externe Bibliotheken
LIBS := -lSDL2 -lm
# zu erzeugendes Programm
BINARY := juliamann

# Compilerflags, Debugging-Symbole, keine Optimierung, alle Warnings
CFLAGS := -g3 -O0 -Wall -Wundef -fmessage-length=0


# das gewünschte Programm aus den Einzelteilen zusammenfügen
$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJS) $(LDFLAGS) $(LIBS)

# erzeuge die Objektdateien aus den Quelldateien
# der Einfachheit halber, kompiliere bei jeder Änderung in den Headerfiles
.c.o: $(INCLUDES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

# gewünschtes Ziel, wenn make ohne Kommandozeilenparameter aufgerufen wird
all: juliamann

# Aufräumarbeiten:
clean:
	-rm -f $(BINARY)
	-rm -f $(OBJS)
	-rm -f $(PRECOMPILEDHEADERS)

.phony: all clean
