TARGET = src/OSK
OBJS = src/main.o
LIBS = -lstdc++ -lpspgu -lpsputility

ROOTDIR = $(realpath .)
INCDIR =
CFLAGS = -O2 -G0 -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align
-Wstrict-overflow=5 -Wwrite-strings -Waggregate-return
CXXFLAGS = $(CFLAGS) -std=c++17 -fexceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 0

LIBDIR =
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSP OSK Sample

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
