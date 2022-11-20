## RSA Encrypion and Decryption Parallelization
```
CED19I002
Paul Babu Kadali
```
---
### Serial Code
```bash
cd OpenMP
make run
```
---
### OpenMP
```bash
cd OpenMP
make runp
```
--- 
### MPI
inside the cluster
change the MPI_CUDA/hosts.txt file according to hosts
```bash
make # compiles the MPI code
make mpirun # executes
```
### CUDA
upload the rsa.zip in MPI_CUDA to google colab change runtime to GPU

then execute the cells in MPI_CUDA/cudaCELLs.txt in the notebook for it to run.
