set build_prefix=build-win

mkdir %build_prefix%-release
PUSHD %build_prefix%-release

cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build .


POPD
