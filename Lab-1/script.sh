> time.txt

# echo "$1"

for ((i=1; i<12; ++i)); 
do  
    rep=$((2**i))
    echo "$rep"
    export OMP_NUM_THREADS=$((rep))
    gcc -fopenmp $1 && ./a.out >> time.txt
done