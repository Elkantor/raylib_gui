#!bin/sh

[ ! -d "bin" ] && mkdir bin
cd bin

proj_name=app
proj_root_dir=$(pwd)/../../

rm -rf ${proj_name}

flags=(
	-std=c99 -w
)

# Include directories
inc=(
	-I../../../libs
)

lib=(
    -L../../../libs
)

# Source files
src=(
	../../../main.c
)

libs=(
	-lraylib
    -lopengl32
    -lgdi32
    -lwinmm
)

# Build
gcc -O1 ${inc[*]} ${lib[*]} ${src[*]} ${flags[*]} ${libs[*]} -lm -o ${proj_name}

# Run
[ ! -d "fonts" ] && echo "[LOG]: fonts folder don't exists, copy it" && cp -R ../../../fonts ./fonts
./app

cd ..