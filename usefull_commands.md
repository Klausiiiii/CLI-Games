### Usefull Commands

## Bei Changes in der CMakeLists.txt
cmake -B build -DCMAKE_BUILD_TYPE=Debug

## Bauen
cmake --build build

## Testing
ctest --test-dir build --output-on-failure
