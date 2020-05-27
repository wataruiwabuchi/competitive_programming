g++ -g -O0 -std=c++14 -D_MY_DEBUG -D_GLIBCXX_DEBUG $1
./a.out < input.txt
cat $1 | clip.exe
