CXX      ?= g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
INCDIR   := include
SRCDIR   := src
BUILDDIR := build
TARGET   := aescrypt

# sources
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

UNAME_S := $(shell uname -s 2>/dev/null || echo Unknown)

# Linux / macOS
ifeq ($(UNAME_S),Linux)
    LDFLAGS += -lssl -lcrypto
endif

ifeq ($(UNAME_S),Darwin)      # macOS
    LDFLAGS += -lssl -lcrypto
endif

ifeq (,$(findstring MINGW,$(UNAME_S)))
else
    LDFLAGS += -lssl -lcrypto
endif

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -I$(INCDIR) $(LDFLAGS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

run: all
	./$(TARGET) -h