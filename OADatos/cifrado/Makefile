#OBJS specifies which files to compile as part of the project
OBJS = main.cpp /home/alexander/Dropbox/UCSP/Repositorio/git/OADatos/modular/Modular.cpp CifradoModular.cpp /home/alexander/Dropbox/UCSP/Repositorio/git/OADatos/modular/Cola.cpp /home/alexander/Dropbox/UCSP/Repositorio/git/OADatos/TxtFile/TxtFile.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -I/home/alexander/Dropbox/UCSP/Repositorio/git/OADatos/modular -I/home/alexander/Dropbox/UCSP/Repositorio/git/OADatos/TxtFile/

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
