###############################################################
# Program:
#     Week 03, QUEUE
#     Brother JonesL, CS235
# Author:
#     Adam Shumway, Jenaca Willans
# Most Difficult Part:
#     the push and copy methods along with the stock program
# Time:
#     around 20 hours
###############################################################
##############################################################                 
# Makefile variables for windows, mac, or linux                                 
###############################################################                 
ifeq ($(OS),Windows_NT)
    #Windows stuff                                                              
    RM = del /f
    PROGRAM = a.exe
    P_EXT = .exe
else
    ifeq ($(shell uname), Linux)
        #Linux stuff                                                            
        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week03.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                              
        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week03.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): queue.h week03.o dollars.o stock.o
	g++ -o $(PROGRAM) week03.o dollars.o stock.o
	$(TAR)

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      week03.o       : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
week03.o: queue.h week03.cpp
	g++ -c week03.cpp

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp


###############################################################                 
# General rules                                                                 
###############################################################                 
clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch


