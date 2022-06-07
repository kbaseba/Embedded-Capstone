# the compiler: Horus uses the GNU C compiler found on the raspberry pi
CC = gcc
 
# compiler flags:
#  -g    		 - this flag adds debugging information to the executable file
#  -Wall 		 - this flag is used to turn on most compiler warnings
#  -lwiringPi	 - this flag is used to add in support for the Pi's GPIO
CFLAGS  = -g -Wall -lwiringPi
 
# The build target, used as the name of the binary
TARGET = RunHorus
# Name of the test target binary
TEST = TestHorus
# Path to the instal directory of Horus
PATH_TO_RUN = /usr/local/bin/
# C object files
OBJS = PiMain.c threadfunctions.c
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(PATH_TO_RUN)$(TARGET) -lpthread

$(TEST): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TEST) -lpthread

clean:
	$(RM) $(PATH_TO_RUN)$(TARGET)

testclean:
	$(RM) $(TEST)
