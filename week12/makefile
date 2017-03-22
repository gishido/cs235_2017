###############################################################
# Program:
#     Week 12, Hash
#     Brother XXXXX, CS235
# Author:
#     <your name here>
# Summary:
#     <put a description here>
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
        TAR = tar -cf week12.tar *.h *.cpp makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                           

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week12.tar *.h *.cpp makefile
    endif
endif
##############################################################
# The main rule
##############################################################
$(PROGRAM): week12.o spellCheck.o
	g++ -o $(PROGRAM) week12.o spellCheck.o -g
	$(TAR)

##############################################################
# The individual components
#      week12.o     : the driver program
#      spellCheck.o   : the spell-check program and driver
##############################################################
week12.o: hash.h week12.cpp list.h
	g++ -c week12.cpp -g

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g

###############################################################                
# General rules                                                                
##############################################################                 

clean:
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch