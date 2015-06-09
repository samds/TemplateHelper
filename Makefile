CC=clang++
CCFLAGS= -std=c++11 -Wall


factorial: 
	$(CC) $(CCFLAGS) factorial.cpp -o factorial

template: 
	$(CC) $(CCFLAGS) template.cpp -o template

clean:
	rm a.out