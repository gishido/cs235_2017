###############################################################
# Program:
#     Week 04, DEQUE
#     Brother JonesL, CS235
# Author:                                                                     
#     Adam Shumway, Jenaca Willans                                            
# Most Difficult Part:                                                        
# 
# Pair Programming Time:                                                      
#
# Total Time:                                                                 
#
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
        TAR = tar -cf week04.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                           

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week04.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): deque.h week04.o nowServing.o
	g++ -o $(PROGRAM) week04.o nowServing.o
	$(TAR)

#a.out: deque.h week04.o nowServing.o
#	g++ -o a.out week04.o nowServing.o
#	tar -cf week04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week04.o       : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
week04.o: deque.h week04.cpp
	g++ -c week04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp

###############################################################          
# General rules                                                         
##############################################################

clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch



