#!/bin/bash
set -e

RAW_DIR=results/raw
PROC_DIR=results/processed
mkdir -p $PROC_DIR

for file in $RAW_DIR/*.txt; do
    algo=$(basename $file .txt)
    outfile_time="$PROC_DIR/${algo}_time.dat"
    outfile_mem="$PROC_DIR/${algo}_mem.dat"

    awk '
    {
        key = $1 " " $2 " " $3; # Mode N M
        time[key] += $4;
        mem[key]  += $5;
        count[key] += 1;
    }
    END {
        for (k in time) {
            split(k, arr, " ");
            N=arr[2]; M=arr[3];
            avg_time = time[k]/count[k];
            avg_mem  = mem[k]/count[k];
            print N, M, avg_time > "'"$outfile_time"'";
            print N, M, avg_mem  > "'"$outfile_mem"'";
        }
    }' "$file"

    sort -k1,1n -k2,2n -o "$outfile_time" "$outfile_time"
    sort -k1,1n -k2,2n -o "$outfile_mem" "$outfile_mem"
done

mkdir -p results/plots

echo "Processed data saved in $PROC_DIR/"
