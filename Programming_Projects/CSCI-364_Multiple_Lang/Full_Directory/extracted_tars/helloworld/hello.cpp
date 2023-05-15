#include <iostream>

int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;

    if (argc == 1) {
        cout << "Hello, world!" << endl;
    } else {
        cout << "Hello, " << argv[1] << endl;
    }
}

