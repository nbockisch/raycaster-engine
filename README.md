# Raycasting engine
A raycaster engine written in C++ with SDL2, currently under development. This
was a project created for educational purposes, to learn more about C++, SDL2,
and CMake.

# Building
The project is currently targeted towards *nix systems, with Windows support
planned down the line. It requires having SDL2 installed.

From within the cloned repo, do the following:
```
mkdir build && cd build
cmake ..
make
./raycaster
```

# Feature Checklist
- [x] Set up CMake compilation
- [x] Create an object-oriented class structure
- [x] Create class for handling game rendering and updating
- [x] Create class for input handling
- [x] Implement player movement
- [ ] Create class for casting rays and rending player view
- [ ] Implement collision-detection
- [ ] Implement saving and loading maps from files
