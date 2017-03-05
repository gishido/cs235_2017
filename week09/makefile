###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother JonesL, CS235
# Author:
#     Adam Shumway, Jenaca Willans	
# Most Difficult Part:                                               
#     The most difficult part is keeping track of where we are
#     in the tree. 	 
# Pair Programming Time:                                               
#     7 hours	
# Total Time:                                                          
#     32 and counting
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
        TAR = tar -cf week09.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                              

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week09.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): week09.o 
	g++ -o $(PROGRAM) week09.o
	$(TAR)


##############################################################
# The individual components
#      week09.o     : the driver program
##############################################################
week09.o: bnode.h bst.h week09.cpp sortBinary.h
	g++ -c week09.cpp -g


###############################################################       
# General rules                                                        
##############################################################         
clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
