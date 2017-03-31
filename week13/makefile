###############################################################
# Program:
#     Week 13, Graph
#     Brother JonesL, CS235
# Author:
#     Adam Shumway, Jenaca Willans
# Most Difficult Part:
#   
# Pair Programming:
#   
# Total time:
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
        TAR = tar -cf week13.tar *.h *.cpp *.txt makefile
    endif
    ifeq ($(shell uname),Darwin)
        #Mac stuff                                                           

        RM = rm -f
        PROGRAM = a.out
        P_EXT = .out
        POSITIONTEST = positionText.out
        MOVETEST = moveTest.out
        TAR = tar -cf week13.tar *.h *.cpp *.txt makefile
    endif
endif
##############################################################
# The main rule
##############################################################
$(PROGRAM): week13.o graph.o maze.o
	g++ -o $(PROGRAM) week13.o graph.o maze.o -g
	$(TAR)

##############################################################
# The individual components
#      week13.o     : the driver program
##############################################################
week13.o: graph.h vertex.h week13.cpp
	g++ -c week13.cpp -g

graph.o: graph.h set.h vertex.h vector.h graph.cpp
	g++ -c graph.cpp -g

maze.o: maze.cpp maze.h vertex.h graph.h
	g++ -c maze.cpp -g

###############################################################                
# General rules                                                                
##############################################################                 

clean:
	$(RM) *$(P_EXT) *.o *.out *.tar *~ *.gch