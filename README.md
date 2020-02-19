# EV3USBConnect

Native Java wrapper of hid api for JavaForEV3 project

Собирается в jar библиотеку, содержащую нативные методы для работы с usb портом, как с потоковым вводом\выводом массива байт
Применяется в [JavaForEV32](https://github.com/megavice1753/JavaForEV32) в качестве реализации **ICommunicator**

1. add native method

2. compile (shift+f11 in netbeans)

3. cd <project_root> javah -o src\cpp\EV3USBConnect.h -jni -classpath build\classes EV3USBConnect.Connector
4. cd src\cpp cl -LD "EV3USBConnect.cpp" -LD "hid.cpp" -Fe"..\..\build\classes\cpp\EV3USBConnect.dll" -I"C:\ProgramFiles\Java\jdk1.8.0_25\include\win32" -I"C:\Program Files\Java\jdk1.8.0_25\include" /link "setupapi.lib"

