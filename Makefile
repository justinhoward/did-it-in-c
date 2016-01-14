# Target binary
TARGET=hello

# Files and directories
BINDIR=bin
SRCDIR=src
INCDIR=include
OBJDIR=obj
OBJEXT=o
SRCEXT=c

# Compiler and linker
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INC=-iquote $(INCDIR)

# Computed values
TARGETFILE=$(BINDIR)/$(TARGET)
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

# Alias for building the target binary
all: $(TARGETFILE)

# Link
$(TARGETFILE): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@

# Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# Remove all generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Prevent make from treating these targets as files
.PHONY: clean all
