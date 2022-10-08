> time.txt

# echo "$1"

for ((i=1; i<8; ++i)); 
do  
    rep=$((2**i))
    echo "$rep"
    export OMP_NUM_THREADS=$((rep))
    	mpicc $1 && mpirun -n $rep -f hosts ./a.out >> time.txt
done