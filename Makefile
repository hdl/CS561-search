agent: clean agent.o task.o bfs.o dfs.o
	g++ -g -o agent agent.o task.o bfs.o dfs.o
agent.o:
	g++ -g -c agent.cpp 
task.o:
	g++ -g -c task.cpp
bfs.o:
	g++ -g -c bfs.cpp
dfs.o:
	g++ -g -c dfs.cpp
run:
	./agent
	cat output.txt
clean:
	rm -rf agent *.o
