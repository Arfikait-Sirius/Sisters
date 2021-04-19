@ECHO OFF

cd .\dir_Modules\libParts

gcc -c ^
     ..\..\dir_Girls\Alice\Alice.c ^
     ..\..\dir_Girls\Chloe\Chloe.c ^
     ..\..\dir_Girls\Dorothy\Dorothy.c ^
     ..\..\dir_Girls\Emily\Emily.c ^
     ..\..\dir_Girls\Kotone\Kotone.c ^
     ..\..\dir_Girls\Louise\Louise.c ^
     ..\..\dir_Girls\Rachel\Rachel.c ^
     ..\..\dir_Girls\Sylvia\Sylvia.c ^
     ..\..\dir_Girls\Tina\Tina.c ^
     ..\..\dir_Girls\Veera\Veera.c ^
     ..\..\dir_Specifications\siscmn.c

cd ..
ar -r libSisters.a .\libParts\*.o > NUL

cd ..
set DIR_SISTERS=%1\sisters
set DIR_SISTERS_SKILLSHEETS=%1\sisters\skillsheets
set DIR_SISTERS_COMMONS=%1\sisters\skillsheets\commons

IF NOT exist %DIR_SISTERS% (
     mkdir %DIR_SISTERS%
     mkdir %DIR_SISTERS_SKILLSHEETS%
     mkdir %DIR_SISTERS_COMMONS%
)

copy .\dir_Modules\Sisters_windows.h %1\Sisters.h > NUL
copy .\dir_Modules\skillsheets\Alice.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Chloe.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Dorothy.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Emily.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Kotone.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Louise.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Rachel.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Sylvia.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Tina.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\Veera.h %DIR_SISTERS_SKILLSHEETS%\. > NUL
copy .\dir_Modules\skillsheets\commons\siscmn.h %DIR_SISTERS_COMMONS%\. > NUL
copy .\dir_Modules\skillsheets\commons\sisdef.h %DIR_SISTERS_COMMONS%\. > NUL
copy .\dir_Modules\skillsheets\commons\sismsg.h %DIR_SISTERS_COMMONS%\. > NUL
copy .\dir_Modules\skillsheets\commons\sisset.h %DIR_SISTERS_COMMONS%\. > NUL
copy .\dir_Modules\libSisters.a %DIR_SISTERS%\. > NUL

echo "Completed!"
