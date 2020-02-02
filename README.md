# Fire Detector (Pixy2 & Arduino ver.) for HoverGames Challenges 2019

![EyeCatch](https://github.com/iwaita2ya/ImageStore/blob/master/fire-detector-with-pixy2-arduino.jpg)

This repository holds source code of fire detector developed for HoverGames Challenge 2019.

In this version I use Arduino Uno with Pixy2 camera for fire detection based on it's color (hue.)

## Things you need
I have tested this program with [Arduino UNO Rev.3](https://www.arduino.cc/en/Guide/ArduinoUno) 
with following devices:

* Piyx2 https://pixycam.com/pixy2/
* LED (generic)
* Register x 3


Please see [here](https://bit.ly/2Ui6TQS) for the complete schematic circuit diagram.

## Installation

You need to configure [PlatformIO Core](https://docs.platformio.org/en/latest/core.html) for build.  
Please prepare platformio core prior to compile.

### Clone & Build
```bash
$ git clone https://github.com/iwaita2ya/HoverGamesChallenge2019_Pixy2-Arduino
$ cd ./HoverGamesChallenge2019_Pixy2-Arduino
$ platformio run
```

### Install
After the build completed, you'll find binary file `firmware.hex` under `.pio/build/uno/` directory located under the project directory.

Connect Arduino Uno onto your PC and upload the binary file using your preferred IDE.

Alternatively you can build & upload at once by adding upload option

    # add "upload" option followed by "run" command
    $ platformio run -t upload
    
please see [here](https://docs.platformio.org/en/stable/userguide/cmd_run.html#cmdoption-platformio-run--target)
for the complete reference of `platformio run` command.