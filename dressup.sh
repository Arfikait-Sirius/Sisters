#!/bin/sh

cd ./dir_Modules/libParts
gcc -c ../../dir_Girls/**/*.c
gcc -c ../../dir_Specifications/siscmn.c

cd ..
ar -r libSisters.a ./libParts/*.o

cd ..
DIR_SISTERS="$1/sisters"
DIR_SISTERS_SKILLSHEETS="$1/sisters/skillsheets"

if [ ! -d $DIR_SISTERS ]; then
     mkdir $DIR_SISTERS
fi
cp ./dir_Modules/Sisters.h $1/.
cp -r ./dir_Modules/skillsheets $DIR_SISTERS/.
cp ./dir_Modules/libSisters.a $DIR_SISTERS/.

echo "Completed!"
