###############################################################
# Program:
#     Week 11, Sorts                                                          
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
        TAR = tar -cf week11.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                           

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week11.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): week11.o
	g++ -o $(PROGRAM) week11.o
	$(TAR)

##############################################################
# The individual components
#      week11.o     : the driver program
##############################################################
week11.o: bnode.h bst.h stack.h week11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c week11.cpp -g


###############################################################                
# General rules                                                                
##############################################################                 

clean:
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
