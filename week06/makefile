###############################################################
# Program:
#     Week 06, NODE
#     Brother JonesL, CS235
# Author:
#     Adam Shumway, Jenaca Willans
# Most Difficult Part:
#     Copy() and "string construct from null error"
# Pair Programming Time:
#     5                                          
# Total Time:
#     17
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
        TAR = tar -cf week06.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                            

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week06.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): node.h week06.o 
	g++ -o $(PROGRAM) week06.o  -g
	$(TAR)

##############################################################
# The individual components
#      week06.o      : the driver program
#      <anything else?>
##############################################################
week06.o: node.h week06.cpp sortInsertion.h
	g++ -c week06.cpp -g

###############################################################              
# General rules                                                              
##############################################################               

clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
