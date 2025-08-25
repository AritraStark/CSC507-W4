#!/bin/bash
set -e

BIN_DIR=bin
RAW_DIR=results/raw
REPEATS=5   

mkdir -p $RAW_DIR

ALGOS=("BFS" "DFS_ITER" "DFS_REC" "DIJKSTRA" "SCC1" "SCC2" "SCC3")

# VARM
for algo in "${ALGOS[@]}"; do
    exe="$BIN_DIR/run_$algo"
    outfile="$RAW_DIR/VARM_$algo.txt"
    echo "Running VARM for $algo..."
    > "$outfile"
    for N in 200 400 600 800 1000; do
        for r in $(seq 1 $REPEATS); do
            $exe --varm $N >> "$outfile"
        done
    done
done

# VARN
for algo in "${ALGOS[@]}"; do
    exe="$BIN_DIR/run_$algo"
    outfile="$RAW_DIR/VARN_$algo.txt"
    echo "Running VARN for $algo..."
    > "$outfile"
    for sparsity in 2n nlogn nsqrtn nc2; do
        for r in $(seq 1 $REPEATS); do
            $exe --varn $sparsity >> "$outfile"
        done
    done
done

echo "Benchmarking complete. Raw data in $RAW_DIR/"
