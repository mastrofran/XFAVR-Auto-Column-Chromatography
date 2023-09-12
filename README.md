<p align="center">
    <img width="50%"
        src="static/imgs/XFAVR_logo.png">
    </img>
</p>
<br>

#### What is it?
XFAVR (Xander and Francesco's Auto Vial Rotator) is a column chromatography device written in C++ and controlled using a programmable microcontroller, such as an Arduino. This device can automatically rotate vials for fractionated liquid collected at a predefined rate of rotation and is primarily used to convert manual silica gel chromatography columns into automated pieces of equipment for research labs.

#### Who can use this?
Absolutely anyone. By following the detailed [**documentation**](https://xfavr.org), anyone can automate fractionated vial collection off of a manual silica column (or any other device that requires manual capture of fractionated liquid using vials).

#### What is involved?
As outlined in the [**documentation**](https://xfavr.org), this device can be built in a few hours using a combination of 3D printing, microcontroller assembly, and software installation.


# Software:

### Install:

#### Project Files:
To begin, please clone this repository using the following command:
```
git clone https://github.com/mastrofran/XFAVR-Auto-Column-Chromatography.git
```

- The [**XFAVR program**](/Code/XFAVR_Code/XFAVR_Code.ino) that runs on the programmable microcontroller to control the device is located in the [Code/XFAVR_Code](/Code/XFAVR_Code) subfolder and was written using C++.

#### Arduino Program:
Download the [official Arduino software](https://www.arduino.cc/en/software) for your computer operating system.

- The recommended way to run the XFAVR program on an programmable microcontroller is to download the official programmable microcontroller program for your chosen computer operating system. This program is used to communicate with programmable microcontroller microcontroller via a computer. Detailed instructions on how to use this program are provided in the documentation.

#### Cura Slicer:
Download the [official Cura Slicer](https://ultimaker.com/software/ultimaker-cura/) for your computer operating system.

- A 3D slicer program is needed to convert the XFAVR device STL files to gcode, which the 3D printer uses as a set of instructions for printing. Detailed instructions on how to use this program are provided in the [**documentation**](https://xfavr.org).

# Hardware:
A list of materials needed for this project are located in the [**documentation**](https://xfavr.org). 

Notes:
- Any microcontroller can be used for this project in theory, however the [Elegoo MEGA R3](https://www.amazon.com/ELEGOO-ATmega2560-ATMEGA16U2-Arduino-Compliant/dp/B01H4ZDYCE/ref=sr_1_3?keywords=elegoo+mega&sr=8-3) microcontroller is the recommended microcontroller for this project due to the number of available Digital I/O and Analog Input Pins.
- A 3D printer is used to print the parts. Any 3D printer will do as long as the printer bed dimensions can fit the parts. We used the [Ender-5 Plus](https://www.creality.com/products/ender-5-plus-3d-printer?spm=..page_1967279.products_display_1.1&spm_prev=..product_1f5050d6-4831-42a7-9d22-0639b58cc3e7.header_1.1) and the [Ender-3 v2 3D](https://www.creality.com/products/ender-3-v2-3d-printer-csco?spm=..page_1967279.products_display_1.1&spm_prev=..index.header_1.1)  printers for this project printer for this project.

⚠️ **WARNING: Do not change the dimensions of any part contained in the 3D printer STL files or the pieces may not fit together during assembly.**


# Documentation:
Official documentation is located here: [**DOCS**](https://xfavr.org)  

There are 3 main components to this project:

1. 3D printed components and assembly
2. Microcontroller assembly
3. Installing the XFAVR software onto the microcontroller

Detailed instructions are outlined in the [**documentation**](https://xfavr.org).

## Support:
Having trouble? Create an issue [here](https://github.com/mastrofran/XFAVR-Auto-Column-Chromatography/issues/new).

## Contributors:
Francesco Mastrocinque: [Github](https://github.com/mastrofran) | [LinkedIn](https://www.linkedin.com/in/francesco-mastrocinque)

Xander Wilcox: [Github](https://github.com/XanderWilcox) | [LinkedIn](https://www.linkedin.com/in/xander-wilcox-01321a21b)


