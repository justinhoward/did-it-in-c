# Target binary
TARGET=run

# Files and directories
BINDIR=bin
SRCDIR=src
INCDIR=include
OBJDIR=obj
MAIN=$(SRCDIR)/main.c
TESTDIR=tests
TESTTARGETDIR=$(TESTDIR)/bin
TESTSUFFIX=_test
OBJEXT=o
SRCEXT=c
INCEXT=h

# Compiler and linker
CC=clang
CFLAGS=-Wall -Wextra -Werror
TESTCFLAGS=$(CFLAGS) $(shell pkg-config --cflags --libs check)
INC=-iquote $(INCDIR)

# Computed values
TARGETFILE=$(BINDIR)/$(TARGET)
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
INCLUDES=$(shell find $(INCDIR) -type f -name *.$(INCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
MAINOBJ=$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(MAIN:.$(SRCEXT)=.$(OBJEXT)))
TESTS=$(shell find $(TESTDIR) -type f -name *$(TESTSUFFIX).$(SRCEXT))
TESTTARGETS=$(patsubst $(TESTDIR)/%, $(TESTTARGETDIR)/%, $(TESTS:.$(SRCEXT)=))

# Alias for building the target binary
all: $(TARGETFILE)

# Link
$(TARGETFILE): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@

# Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(INCLUDES)
	@mkdir -p $(dir $@)
	$(CC) $(INC) -c -o $@ $< $(CFLAGS)

# Remove all generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(TESTTARGETDIR)

test: $(TESTTARGETS)
	@for test in $^; do "$$test"; done

lint: $(SOURCES) $(INCLUDES)
	cpplint $(SOURCES) $(INCLUDES) $(TESTS)

# Compile test
$(TESTTARGETDIR)/%: $(TESTDIR)/%.$(SRCEXT) $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(INC) -o $@ $< $(filter-out $(MAINOBJ), $(OBJECTS)) $(TESTCFLAGS)

# Prevent make from treating these targets as files
.PHONY: all clean test lint
