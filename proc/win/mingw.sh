#!bin/sh

[ ! -d "bin" ] && mkdir bin
cd bin

proj_name=app
proj_root_dir=$(pwd)/../../

rm -rf ${proj_name}

flags=(
	-std=c99 -w
)

lib=(
    -L../../../deps/raylib-3.7.0/lib
)

# Source files
src=(
	../../../main.c
)

libs=(
	-lraylibdll
)

# Build
zig cc -O1 ${inc[*]} ${lib[*]} ${src[*]} ${flags[*]} ${libs[*]} -o ${proj_name}

# Run
[ ! -d "fonts" ] && echo "[LOG]: fonts folder don't exists, copy it" && cp -R ../../../fonts ./fonts && cp ../../../deps/raylib-3.7.0/lib/raylib.dll ./raylib.dll
./app

cd ..