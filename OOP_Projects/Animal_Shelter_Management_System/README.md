## Building Project

### Commands
```
1. Go to project path.
2. mkdir build
3. cd build
4. check g++ ---version, mingw32-make --version (Make sure packages are installed and set in environment path in windows)
5. cmake -G "MinGW Makefiles" .. (To configure the project)
6. Run mingw32-make
7. It will generate application, you can use application now.
8. Remove build to create application again.
```