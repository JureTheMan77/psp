TARGET = Graphics
OBJS = $(wildcard *.cpp) $(wildcard *.c)
LIBS = -lstdc++ -lpspgu

INCDIR =
CFLAGS = -G0 -Wall -O2 -std=c++11
CXXFLAGS = $(CFLAGS) -fno-rtti -fexceptions
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Graphics
#game icon, 144x80px
PSP_EBOOT_ICON = logo_icon.png
#PSP_EBOOT_ICON1 = logo.png
#background image, 480x272 px
PSP_EBOOT_PIC1 = logo_background.png
#PSP_EBOOT_UNKPNG = logo.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak