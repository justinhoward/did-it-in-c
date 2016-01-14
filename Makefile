# Target binary
TARGET=hello

# Compiler and linker
CC=gcc
CFLAGS=-Wall -Wextra -Werror

# Files and directories
BINDIR=bin
SRCDIR=src
OBJDIR=obj
OBJEXT=o
SRCEXT=c

# Computed values
TARGETFILE=$(BINDIR)/$(TARGET)
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

# Alias for building the target binary
all: $(TARGETFILE)

# Link
$(TARGETFILE): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $< -o $@

# Compile
$(OBJECTS): $(SOURCES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Prevent make from treating these targets as files
.PHONY: clean all
