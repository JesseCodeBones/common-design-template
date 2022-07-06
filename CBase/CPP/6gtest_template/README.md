# install gtest
#### Linux  
```shell
sudo apt install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
cd lib
sudo cp *.a /usr/lib
```
### Apple Mac
```shell
brew install googletest
```
### Windows
Install from source
```shell
git clone https://github.com/google/googletest.git
```
