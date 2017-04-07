###############################################################
# Program:
#     Week 07, LIST
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
        TAR = tar -cf week07.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                            

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week07.tar *.h *.cpp makefile
    endif
endif
##############################################################
# The main rule
##############################################################
$(PROGRAM): list.h week07.o fibonacci.o
	g++ -o $(PROGRAM) week07.o fibonacci.o
	$(TAR)

##############################################################
# The individual components
#      week07.o       : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
week07.o: list.h week07.cpp
	g++ -c week07.cpp

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -c fibonacci.cpp

###############################################################              
# General rules                                                              
##############################################################               

clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch