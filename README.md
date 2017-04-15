# Embedding python in C++ with pybind11

To build and run:

    mkdir build && cd build
    cmake .. -G Xcode (or whatever C++11 compliant generator you like)
    cmake --build . --config Release
    PYTHONHOME=/Users/ian/anaconda/ Release/mpl_embed

## License:

MIT
