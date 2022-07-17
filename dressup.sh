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
cp ./dir_Modules/Sisters_mac.h $1/Sisters.h
cp \
     ./dir_Girls/Alice/Alice.h \
     ./dir_Girls/Chloe/Chloe.h \
     ./dir_Girls/Dorothy/Dorothy.h \
     ./dir_Girls/Emily/Emily.h \
     ./dir_Girls/Grace/Grace.h \
     ./dir_Girls/Kotone/Kotone.h \
     ./dir_Girls/Louise/Louise.h \
     ./dir_Girls/Rachel/Rachel.h \
     ./dir_Girls/Sylvia/Sylvia.h \
     ./dir_Girls/Tina/Tina.h \
     ./dir_Girls/Veera/Veera.h \
     $DIR_SISTERS_SKILLSHEETS/.
cp \
     ./dir_Modules/skillsheets/commons/siscmn.h \
     ./dir_Modules/skillsheets/commons/sisdef.h \
     ./dir_Modules/skillsheets/commons/sismsg.h \
     ./dir_Modules/skillsheets/commons/sisset.h \
     $DIR_SISTERS_COMMONS/.
cp ./dir_Modules/libSisters.a $DIR_SISTERS/.

echo "Completed!"
