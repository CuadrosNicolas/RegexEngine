CC = g++-7
CFLAGS = -Wall -std=c++1z -g
EXEC_NAME = bin/SXR
OBJECTS = bin/objects/
DIR = bin bin/objects
OBJ_FILES =  $(OBJECTS)StringIterator.o $(OBJECTS)GroupBeginNode.o $(OBJECTS)GroupEndNode.o $(OBJECTS)Regex.o $(OBJECTS)Match.o $(OBJECTS)AnchorNode.o $(OBJECTS)AssemblyNode.o $(OBJECTS)CounterState.o $(OBJECTS)EscapeState.o $(OBJECTS)SetState.o $(OBJECTS)SetNode.o $(OBJECTS)EngineState.o $(OBJECTS)BuildState.o  $(OBJECTS)Lazy.o $(OBJECTS)DecoratorVisitor.o $(OBJECTS)NodeI.o $(OBJECTS)Engine.o  $(OBJECTS)EndNode.o $(OBJECTS)Counter.o $(OBJECTS)CharNode.o $(OBJECTS)BeginNode.o $(OBJECTS)main.o

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)


$(EXEC_NAME) : $(DIR) $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

$(OBJECTS)%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(DIR) :
	mkdir bin
	mkdir bin/objects