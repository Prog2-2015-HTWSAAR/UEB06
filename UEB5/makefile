makefile:
DEL_LIST = *.o *.exe *stackdump

all: project_ueb_05 doc
clean:
	rm -f $(DEL_LIST)
build: project_ueb_05
	g++ -o ueb05 *.o
doc: 
	/Applications/Doxygen/doxygen doxyfile
rebuild: clean all
project_ueb_05: 
	g++ -c -Wall -pedantic *.cpp -std=c++11
