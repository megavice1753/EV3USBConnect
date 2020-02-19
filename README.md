# EV3USBConnect

Native Java wrapper of hid api for JavaForEV3 project

0)add native method
1)compile (shift+f11 in netbeans)
2) cd <project_root> 
javah -o src\cpp\EV3USBConnect.h -jni -classpath build\classes EV3USBConnect.Connector
3)cd src\cpp
cl -LD "EV3USBConnect.cpp" -LD "hid.cpp" -Fe"..\..\build\classes\cpp\EV3USBConnect.dll" -I"C:\ProgramFiles\Java\jdk1.8.0_25\include\win32" -I"C:\Program Files\Java\jdk1.8.0_25\include" /link "setupapi.lib"

cl -LD "TestJNI.cpp" -LD "hid.cpp" -Fe"..\..\build\classes\cpp\TestJNI.dll" -I"C:\ProgramFiles\Java\jdk1.8.0_25\include\win32" -I"C:\Program Files\Java\jdk1.8.0_25\include" /link "setupapi.lib"
