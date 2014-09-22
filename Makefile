agent: clean agent.o task.o
	g++ -g -o agent agent.o task.o
agent.o:
	g++ -g -c agent.cpp 
task.o:
	g++ -g -c task.cpp

run: agent
	./agent
clean:
	rm -rf agent *.o
