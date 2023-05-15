// Mason Motschke - CSCI 364

#include <algorithm>    // min, max
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>      // exit
#include <string>

void usage(char *name) {
    printf("Usage: %s <bw output file> <rgb input file> <num rows> <num cols>\n", name);
}

void load_rgbfile(std::string filename, int *rgb_data, int height, int width) {
    std::ifstream ifs(filename, std::ifstream::in);
    int red, green, blue;
    int rgb_index;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // read the channel values
            ifs >> red >> green >> blue;

            // store in array
            rgb_index = 3 * row * width + col;
            rgb_data[rgb_index] = red;
            rgb_data[rgb_index + 1] = green;
            rgb_data[rgb_index + 2] = blue;
        }
    }

    ifs.close();
}

void convert_avg(int *in, int *out, int height, int width) {
    int rgb_index;
    int red, green, blue;
    int grey_index;
    int grey;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            rgb_index = 3 * row * width + col;

            red = in[rgb_index];
            green = in[rgb_index + 1];
            blue = in[rgb_index + 2];

            grey = (red + green + blue) / 3;
            grey_index = row * width + col;
            out[grey_index] = grey;
        }
    }
}

__global__ void device_av(int n, int *rgb, int *bw, int width){
  //printf("Hello\n");
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  if (i < n){
    for (int col = 0; col < width; col++) {
      int rgb_index = 3 * i * width + col;

      int red = rgb[rgb_index];
      int green = rgb[rgb_index + 1];
      int blue = rgb[rgb_index + 2];

      int grey = (red + green + blue) / 3;
      int grey_index = i * width + col;
      bw[grey_index] = grey;
    }    
  }
}

void write_bwfile(std::string filename, int *bw_data, int height, int width) {
    std::ofstream ofs(filename, std::ofstream::out);

    int grey_index;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            grey_index = row * width + col;
            ofs << bw_data[grey_index] << " ";
        }
        ofs << "\n";
    }
    ofs << "\n";

    ofs.close();
}

int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;

    // check command line args count
    if (argc != 5) {
        usage(argv[0]);
        exit(1);
    }

    // get values from the command line
    std::string outfile = argv[1];
    std::string infile = argv[2];
    const int HEIGHT = std::stoi(argv[3]);
    const int WIDTH = std::stoi(argv[4]);

    cout << "Output file: " << outfile << endl;
    cout << "Input file: " << infile << endl;
    cout << "HEIGHT: " << HEIGHT << endl;
    cout << "WIDTH: " << WIDTH << endl;

    // create data structures

    // - GPU
    int n = HEIGHT;

    int *rgb_data = new int[HEIGHT * WIDTH * 3];        // 3 the for red, green, and blue values
    int *bw_data = new int[HEIGHT * WIDTH];

    // load rgb data from file
    load_rgbfile(infile, rgb_data, HEIGHT, WIDTH);
    
    // - GPU
    int *drgb, *dbw;
    cudaMalloc(&drgb, sizeof(int) * HEIGHT * WIDTH * 3);
    cudaMalloc(&dbw, sizeof(int) * HEIGHT * WIDTH);

    cudaMemcpy(drgb, rgb_data, sizeof(int) * HEIGHT * WIDTH * 3, cudaMemcpyHostToDevice);

    // convert rgb to greyscale using the "average" method
    //convert_avg(rgb_data, bw_data, HEIGHT, WIDTH);

    device_av<<<32, 94>>>(n, drgb, dbw, WIDTH);
    cudaDeviceSynchronize();

    // write greyscale data to file
    cudaMemcpy(bw_data, dbw, sizeof(int) * HEIGHT * WIDTH, cudaMemcpyDeviceToHost);
    write_bwfile(outfile, bw_data, HEIGHT, WIDTH);

    // free memory

    // - GPU
    cudaFree(drgb);
    cudaFree(dbw);

    delete []rgb_data;
    delete []bw_data;
}
