mkdir build
cd build
SET QT_BIN="c:/Qt/5.13.0/msvc2017_64/bin"
::SET GENERATOR="Visual Studio 15 2017"
cmake .. -DCMAKE_PREFIX_PATH=%QT_BIN% -A "x64"
PAUSE