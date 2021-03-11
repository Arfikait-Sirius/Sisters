#!/bin/sh

cd ./dir_Modules/libParts
gcc -c ../../dir_Girls/**/*.c

cd ..
ar -r libSisters.a ./libParts/*.o

cd ..
DIR_SISTERS="$1/sisters"
if [ ! -d ${DIR_SISTERS} ]; then
     mkdir $DIR_SISTERS
fi
cp ./dir_Modules/Sisters.h $1/.
cp ./dir_Modules/libSisters.a $DIR_SISTERS/.

echo "Completed!"
