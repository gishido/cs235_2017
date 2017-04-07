###############################################################
# Program:
#     Week 08, BINARY TREE
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
        TAR = tar -cf week08.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                            

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week08.tar *.h *.cpp makefile
    endif
endif

##############################################################
# The main rule
##############################################################
$(PROGRAM): bnode.h week08.o huffman.o
	g++ -o $(PROGRAM) week08.o huffman.o
	$(TAR)

##############################################################
# The individual components
#      week08.o       : the driver program
#      huffman.o    :
#      <anything else?>
##############################################################
week08.o: bnode.h huffman.h week08.cpp
	g++ -c week08.cpp -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g

###############################################################              
# General rules                                                              
##############################################################               

clean :
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch
