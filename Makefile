#
# Makefile:
#	wiringPi - Wiring Compatable library for the Raspberry Pi
#	https://projects.drogon.net/wiring-pi
#
#	Copyright (c) 2012 Gordon Henderson
#################################################################################

#DEBUG	= -g -O0
DEBUG	= -O3
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L/usr/local/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm

# Should not alter anything below this line
###############################################################################

SRC	=	blink.c stepper.c			\
		pwm.c					\
		speed.c wfi.c isr.c isr-osc.c	\
		softPwm.c softTone.c 		\
		delayTest.c

OBJ	=	$(SRC:.c=.o)

BINS	=	$(SRC:.c=)

all:	
	@cat README.TXT
	@echo "    $(BINS)" | fmt
	@echo ""

really-all:	$(BINS)

stepper: stepper.o
	@echo [link]
	@$(CC) -o $@ stepper.o $(LDFLAGS) $(LDLIBS)

speed:	speed.o
	@echo [link]
	@$(CC) -o $@ speed.o $(LDFLAGS) $(LDLIBS)

clock:	clock.o
	@echo [link]
	@$(CC) -o $@ clock.o $(LDFLAGS) $(LDLIBS)

wfi:	wfi.o
	@echo [link]
	@$(CC) -o $@ wfi.o $(LDFLAGS) $(LDLIBS)

isr:	isr.o
	@echo [link]
	@$(CC) -o $@ isr.o $(LDFLAGS) $(LDLIBS)

isr-osc:	isr-osc.o
	@echo [link]
	@$(CC) -o $@ isr-osc.o $(LDFLAGS) $(LDLIBS)


pwm:	pwm.o
	@echo [link]
	@$(CC) -o $@ pwm.o $(LDFLAGS) $(LDLIBS)

softPwm:	softPwm.o
	@echo [link]
	@$(CC) -o $@ softPwm.o $(LDFLAGS) $(LDLIBS)

softTone:	softTone.o
	@echo [link]
	@$(CC) -o $@ softTone.o $(LDFLAGS) $(LDLIBS)

delayTest:	delayTest.o
	@echo [link]
	@$(CC) -o $@ delayTest.o $(LDFLAGS) $(LDLIBS)

serialRead:	serialRead.o
	@echo [link]
	@$(CC) -o $@ serialRead.o $(LDFLAGS) $(LDLIBS)

serialTest:	serialTest.o
	@echo [link]
	@$(CC) -o $@ serialTest.o $(LDFLAGS) $(LDLIBS)

okLed:	okLed.o
	@echo [link]
	@$(CC) -o $@ okLed.o $(LDFLAGS) $(LDLIBS)

tone:	tone.o
	@echo [link]
	@$(CC) -o $@ tone.o $(LDFLAGS) $(LDLIBS)

ds1302:	ds1302.o
	@echo [link]
	@$(CC) -o $@ ds1302.o $(LDFLAGS) $(LDLIBS)


.c.o:
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "[Clean]"
	@rm -f $(OBJ) *~ core tags $(BINS)

tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

depend:
	makedepend -Y $(SRC)

# DO NOT DELETE
