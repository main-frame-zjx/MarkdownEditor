# MarkdownEditor
复旦大学2023年OOAD课程lab


mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make 	//若编译太慢使用 make -j
cd ..

cd .\manual_test\
copy ../MarkDownEditor.exe ./MarkDownEditor.exe