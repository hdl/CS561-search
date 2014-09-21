agent: clean
	g++ agent.cpp -g -o agent
run: agent
	./agent
clean:
	rm -rf agent
