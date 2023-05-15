#include <cstdio>

__global__ void parallel() {
  printf("This is running in parallel.\n");
}

int main() {
  dim3 dimGrid(2, 2);
  dim3 dimBlock(2, 2, 2);

  parallel<<<dimGrid, dimBlock>>>();
  cudaDeviceSynchronize();
}

