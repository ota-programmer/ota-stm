# Over-The-Air Programmer (OTA Programmer)
Over-the-air programming (OTA programming) refers to various methods of distributing new software, configuration settings, and even updating encryption keys to devices like mobile phones, set-top boxes, electric cars.
This project is implemented to program BlueBill Board (STM32 Micro-controller) over the air using a website connected to a cloud database (Firebase) and NodeMCU board to get the code from internet for sending it to STM to write it to the Flash Memory using the Bootloader flashed on the first 8 kB of Flash Memory.
## ‣ Circuit Diagram
![Circuit Diagram](https://ota-programmer.github.io/diagram.jpg)


## ‣ The project is divided into three mini-projects

### 1. Website
The website is responsible for letting the user upload a ```.hex``` file to a cloud database (Firebase) to be ready to be received by NodeMCU.
The website only allows ```.hex``` to be uploaded, it also have some ```.hex``` file examples to let the user test the project.
Examples are
- ```.hex``` file to only erase the application area in Flash memory.
- ```.hex``` file to blink the leds connected to pin A0,A1,A2 every 0.5 second.
- ```.hex``` file to left-shift two leeds connected to pin A0,A1,A2 every 0.5 second.
- ```.hex``` file to right-shift two leeds connected to pin A0,A1,A2 every 0.5 second.

The website also allows the user to vheck if NodeMCU is connected to Internet.
### 2. NodeMCU
Once a new ```.hex``` file is uploaded to Firebase, NodeMCU reads its content to try sending it line by line to STM through UART.
NodeMCU code has a ```config.h``` file to let the user choose the following
- UART Baudrate.
- Wi-Fi SSID and Password.
- The timeout interval of trying to connect to Wi-Fi.

### 3. STM
On reset, STM Bootloader waits for 5 seconds if there is any code received from NodeMCU. If any, it will first erase the application area and then flash the code received. Once it finished, it will run the application code.
If no code received from NodeMCU for 5 seconds, it will jump to latest flashed application code.

## ‣ Future Improvements
- Let the user upload multiple application files, and choose which application to run.
- Impove how STM receives the code, instead of waiting 5 seconds on every reset.


## ‣ Programming Languages
``` sh
C, C++, HTML, CSS, JavaScript.
```
## ‣ Hardware Required
- NodeMCU V1.0 Board
- BlueBill Board


## ‣ Links
- The source code of all project can be found on this [GitHub Organization](https://github.com/ota-programmer).
- The website for uploading the ```.hex``` file can be found on this [link](https://ota-programmer.github.io).

## ‣ Video:
A video illustrating the project can be found on this link.

[![Video](https://img.youtube.com/vi/v=N_zM7etQvOw/0.jpg)](https://www.youtube.com/watch?N_zM7etQvOw)


## ‣ Developer
This project is developed by [Ahmed Hassan](https://ahmed-hassann.github.io/).
