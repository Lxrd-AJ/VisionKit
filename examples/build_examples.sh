CWD = "$(./)"
cd ./../build
rm -rf *
cp ./../examples/bp.jpg ./
cmake ..
make
cd ${CWD}