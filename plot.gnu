set terminal pngcairo size 1200,800 enhanced font 'Verdana,10'
set datafile separator whitespace

# VARN: Time vs N: 
set output "results/plots/varn_time.png"
set title "VARN: Time vs N"
set xlabel "Number of Nodes (N)"
set ylabel "Execution Time (s)"
plot \
  "results/processed/VARN_BFS_time.dat" using 1:3 title "BFS" with linespoints, \
  "results/processed/VARN_DFS_ITER_time.dat" using 1:3 title "DFS_ITER" with linespoints, \
  "results/processed/VARN_DFS_REC_time.dat" using 1:3 title "DFS_REC" with linespoints, \
  "results/processed/VARN_DIJKSTRA_time.dat" using 1:3 title "DIJKSTRA" with linespoints, \
  "results/processed/VARN_SCC1_time.dat" using 1:3 title "SCC1" with linespoints, \
  "results/processed/VARN_SCC2_time.dat" using 1:3 title "SCC2" with linespoints, \
  "results/processed/VARN_SCC3_time.dat" using 1:3 title "SCC3" with linespoints

# VARN: Memory vs N:
set output "results/plots/varn_mem.png"
set title "VARN: Memory vs N"
set xlabel "Number of Nodes (N)"
set ylabel "Memory Usage (KB)"
plot \
  "results/processed/VARN_BFS_mem.dat" using 1:3 title "BFS" with linespoints, \
  "results/processed/VARN_DFS_ITER_mem.dat" using 1:3 title "DFS_ITER" with linespoints, \
  "results/processed/VARN_DFS_REC_mem.dat" using 1:3 title "DFS_REC" with linespoints, \
  "results/processed/VARN_DIJKSTRA_mem.dat" using 1:3 title "DIJKSTRA" with linespoints, \
  "results/processed/VARN_SCC1_mem.dat" using 1:3 title "SCC1" with linespoints, \
  "results/processed/VARN_SCC2_mem.dat" using 1:3 title "SCC2" with linespoints, \
  "results/processed/VARN_SCC3_mem.dat" using 1:3 title "SCC3" with linespoints

# VARM: Time vs M:
set output "results/plots/varm_time.png"
set title "VARM: Time vs M"
set xlabel "Number of Edges (M)"
set ylabel "Execution Time (s)"
plot \
  "results/processed/VARM_BFS_time.dat" using 2:3 title "BFS" with linespoints, \
  "results/processed/VARM_DFS_ITER_time.dat" using 2:3 title "DFS_ITER" with linespoints, \
  "results/processed/VARM_DFS_REC_time.dat" using 2:3 title "DFS_REC" with linespoints, \
  "results/processed/VARM_DIJKSTRA_time.dat" using 2:3 title "DIJKSTRA" with linespoints, \
  "results/processed/VARM_SCC1_time.dat" using 2:3 title "SCC1" with linespoints, \
  "results/processed/VARM_SCC2_time.dat" using 2:3 title "SCC2" with linespoints, \
  "results/processed/VARM_SCC3_time.dat" using 2:3 title "SCC3" with linespoints

# VARM: Memory vs M:
set output "results/plots/varm_mem.png"
set title "VARM: Memory vs M"
set xlabel "Number of Edges (M)"
set ylabel "Memory Usage (KB)"
plot \
  "results/processed/VARM_BFS_mem.dat" using 2:3 title "BFS" with linespoints, \
  "results/processed/VARM_DFS_ITER_mem.dat" using 2:3 title "DFS_ITER" with linespoints, \
  "results/processed/VARM_DFS_REC_mem.dat" using 2:3 title "DFS_REC" with linespoints, \
  "results/processed/VARM_DIJKSTRA_mem.dat" using 2:3 title "DIJKSTRA" with linespoints, \
  "results/processed/VARM_SCC1_mem.dat" using 2:3 title "SCC1" with linespoints, \
  "results/processed/VARM_SCC2_mem.dat" using 2:3 title "SCC2" with linespoints, \
  "results/processed/VARM_SCC3_mem.dat" using 2:3 title "SCC3" with linespoints
