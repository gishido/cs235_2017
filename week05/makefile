###############################################################
# Program:
#     Week 05, SET
#     Brother JonesL, CS235
# Author:                                                                     
#     Adam Shumway, Jenaca Willans                                         
# Most Difficult Part:
#     Dealing with returning iterators, insert and sort was
#       tough
# Pair Programming Time:                                                     
#     
# Total Time:
#   12 hrs - tests 1-4 + extra credit                                                                
#
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
        TAR = tar -cf week05.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                            

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week05.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################

$(PROGRAM): set.h week05.o goFish.o card.o
	g++ -o $(PROGRAM) week05.o goFish.o card.o
	$(TAR)

#a.out: week05.o goFish.o card.o
#	g++ -o a.out week05.o goFish.o card.o
#	tar -cf week05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week05.o       : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
week05.o: set.h goFish.h week05.cpp
	g++ -c week05.cpp

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -c goFish.cpp

card.o: card.h card.cpp
	g++ -c card.cpp 


###############################################################              
# General rules                                                              
##############################################################               

clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
