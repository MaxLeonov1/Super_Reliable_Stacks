CFLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
	   -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
	   -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -g -pipe -fexceptions \
	   -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
	   -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
	   -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
	   -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
	   -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

DEBUG_FLAGS = -DDEBUG

SOURCES = main.cpp stack_functions.cpp error_functions.cpp stack_tests.cpp

LDFLAGS =
OBJDIR = obj
CXX = g++
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
EXECUTABLE = stack_prj

COMPILE_MODE ?= debug

ifeq ( $(COMPILE_MODE), debug )
	CFLAGS += $(DEBUG_FLAGS)
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: source/%.cpp
	@mkdir -p $(@D)
	@ $(CXX) $(CFLAGS) -I./include -c $< -o $@

clean:
	@ rm -rf $(OBJDIR)