#!/bin/sh

cd ./dir_Modules/libParts

gcc -c \
     ../../dir_Girls/Alice/Alice.c \
     ../../dir_Girls/Chloe/Chloe.c \
     ../../dir_Girls/Dorothy/Dorothy.c \
     ../../dir_Girls/Emily/Emily.c \
     ../../dir_Girls/Grace/Grace.c \
     ../../dir_Girls/Kotone/Kotone.c \
     ../../dir_Girls/Louise/Louise.c \
     ../../dir_Girls/Rachel/Rachel.c \
     ../../dir_Girls/Sylvia/Sylvia.c \
     ../../dir_Girls/Tina/Tina.c \
     ../../dir_Girls/Veera/Veera.c \
     ../../dir_Specifications/siscmn.c

cd ..
ar -r libSisters.a ./libParts/*.o

cd ..
DIR_SISTERS="$1/sisters"
DIR_SISTERS_SKILLSHEETS="$1/sisters/skillsheets"
DIR_SISTERS_COMMONS="$1/sisters/skillsheets/commons"

if [ ! -d $DIR_SISTERS ]; then
     mkdir $DIR_SISTERS
     mkdir $DIR_SISTERS_SKILLSHEETS
     mkdir $DIR_SISTERS_COMMONS
fi
cp ./dir_Modules/Sisters.h $1/.
cp \
     ./dir_Modules/skillsheets/Alice.h \
     ./dir_Modules/skillsheets/Chloe.h \
     ./dir_Modules/skillsheets/Dorothy.h \
     ./dir_Modules/skillsheets/Emily.h \
     ./dir_Modules/skillsheets/Grace.h \
     ./dir_Modules/skillsheets/Kotone.h \
     ./dir_Modules/skillsheets/Louise.h \
     ./dir_Modules/skillsheets/Rachel.h \
     ./dir_Modules/skillsheets/Sylvia.h \
     ./dir_Modules/skillsheets/Tina.h \
     ./dir_Modules/skillsheets/Veera.h \
     $DIR_SISTERS_SKILLSHEETS/.
cp \
     ./dir_Specifications/siscmn.h \
     ./dir_Specifications/sisdef.h \
     ./dir_Runtimefiles/sismsg.h \
     ./dir_Runtimefiles/sisset.h \
     $DIR_SISTERS_COMMONS/.
cp ./dir_Modules/libSisters.a $DIR_SISTERS/.

echo "Completed!"
