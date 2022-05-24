# the compiler: gcc for C program, define as g++ for C++
CC = gcc
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
 
# The build target 
TARGET = RunHorus
TEST = TestHorus
PATH_TO_RUN = ../../run/
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