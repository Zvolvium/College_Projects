#include <cstdio>

void printProperties(int);

int main(int argc, char *argv[]) {
    int nDevices = 0;
    cudaError_t err = cudaGetDeviceCount(&nDevices);

    if (err != cudaSuccess) {
        printf("%s\n", cudaGetErrorString(err));
    } else {
        printf("Number of devices: %d\n", nDevices);
    }

    for (int i = 0; i < nDevices; i++) {
        printProperties(i);
    }
}

void printProperties(int i) {
    struct cudaDeviceProp cdp;
    cudaGetDeviceProperties(&cdp, i);

    printf("\nCUDA Device Properties - Device: %d\n", i);
    printf("----------------------------------\n");
    printf("  Device name: %s\n", cdp.name);
    printf("  Compute capability: %d.%d\n", cdp.major, cdp.minor);
	printf("  Total global memory: %lu bytes\n", cdp.totalGlobalMem);
    printf("  Total constant memory: %lu bytes\n", cdp.totalConstMem);
	printf("  Max grid size, dim(0): %d\n", cdp.maxGridSize[0]);
	printf("  Max grid size, dim(1): %d\n", cdp.maxGridSize[1]);
	printf("  Max grid size, dim(2): %d\n", cdp.maxGridSize[2]);
	printf("  Max threads per block: %d\n", cdp.maxThreadsPerBlock);
	printf("  Max block size, dim(0): %d\n", cdp.maxThreadsDim[0]);
	printf("  Max block size, dim(1): %d\n", cdp.maxThreadsDim[1]);
	printf("  Max block size, dim(2): %d\n", cdp.maxThreadsDim[2]);
	printf("  Shared memory per block: %lu bytes\n", 
            cdp.sharedMemPerBlock);
	printf("  Registers per block: %d\n", cdp.regsPerBlock);
	printf("  Clock frequency: %d khz\n", cdp.clockRate);
	printf("  Asynchronous engines: %d\n", cdp.asyncEngineCount);
	printf("  Multiprocessors on device: %d\n", 
            cdp.multiProcessorCount);
    //printf("  CUDA Cores/MP: %3d\n", _ConvertSMVer2Cores(cdp.major, cdp.minor));
    printf("  Concurrent kernels: %s\n", cdp.concurrentKernels ? "yes" : "no");
    printf("  Compute mode: %d\n", cdp.computeMode);
    printf("and still more properties...\n");
}
