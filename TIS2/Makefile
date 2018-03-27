TARGET = TIS2
OBJS = main.o
LIBS = -lstdc++ -lpspdebugkb

INCDIR =
CFLAGS = -G0 -Wall -O2 -std=c++14
CXXFLAGS = $(CFLAGS) -fno-rtti -fexceptions
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = TIS2
PSP_EBOOT_ICON = logo.png
PSP_EBOOT_ICON1 = logo.png
#PSP_EBOOT_PIC1 = logo.png
#PSP_EBOOT_UNKPNG = logo.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak