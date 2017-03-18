###############################################################
# Program:
#     Week 10, Map
#     Brother JonesL, CS235
# Author:
#     Adam Shumway, Jenaca Willans
# Pair Programming:
#	6 hours
# Total Time:
#       22 hours
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
        TAR = tar -cf week10.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                              

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week10.tar *.h *.cpp makefile
    endif
endif
##############################################################
# The main rule
##############################################################
$(PROGRAM): week10.o wordCount.o
	g++ -o $(PROGRAM) week10.o wordCount.o 
	$(TAR)

##############################################################
# The individual components
#      week10.o       : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
week10.o: bnode.h bst.h pair.h map.h week10.cpp
	g++ -c week10.cpp

wordCount.o: map.h wordCount.h wordCount.cpp bnode.h bst.h
	g++ -c wordCount.cpp 

###############################################################       
# General rules                                                        
##############################################################         
clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
