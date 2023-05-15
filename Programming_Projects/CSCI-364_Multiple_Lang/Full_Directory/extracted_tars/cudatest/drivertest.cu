#include <cuda.h>
#include <cstdio>

int main(int argc, char *argv[]) {
    int driver_version = 0;
    int runtime_version = 0;

    cudaError_t err1 = cudaDriverGetVersion(&driver_version);
    cudaError_t err2 = cudaRuntimeGetVersion(&runtime_version);
    if (err1 != cudaSuccess) {
        printf("err1 %s \n", cudaGetErrorString(err1));
    }
    if (err2 != cudaSuccess) {
        printf("err2 %s \n", cudaGetErrorString(err2));
    }

    printf("Driver version: %d, Runtime version: %d\n",
            driver_version, runtime_version);
    
    printf("Driver API version: %d\n", CUDA_VERSION);
}

