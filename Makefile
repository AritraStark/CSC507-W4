CXX = g++
CXXFLAGS = -O2 -std=c++17
SRC = src/main.cpp
BIN_DIR = bin

ALGORITHMS = BFS DFS_ITER DFS_REC DIJKSTRA SCC1 SCC2 SCC3
TARGETS = $(patsubst %, $(BIN_DIR)/run_%, $(ALGORITHMS))

all: $(TARGETS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/run_%: $(SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -DALGO=$* $(SRC) -o $@

clean:
	rm -rf $(BIN_DIR)/* results/raw/* results/processed/* results/plots/*
