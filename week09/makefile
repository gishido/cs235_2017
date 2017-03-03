###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother JonesL, CS265
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
$(PROGRAM): bnode.h bst.h week09.o sortBinary.o
	g++ -o $(PROGRAM) week09.o sortBinary.o
	$(TAR)


##############################################################
# The individual components
#      week09.o     : the driver program
##############################################################
week09.o: bnode.h bst.h stack.h week09.cpp sortBinary.h
	g++ -c week09.cpp -g


###############################################################       
# General rules                                                        
##############################################################         
clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
