CC = g++
CXXFLAGS = -std=c++14
ODIR = out
SDIR = src
IDIR = include

_OBJS = Trie.o TrieNode.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp $(IDIR)/%.h 
	$(CC) -c -o $@ $< $(CXXLAGS) 

app: $(OBJS)
	$(CC) $(OBJS) $(SDIR)/app.cpp -o app.out $(CXXFLAGS) -lncurses
