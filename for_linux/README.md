# Project Title

Keylogger for Linux

## Description

Keyboard tracking software that works on Linux distributions.

## Getting Started

### Dependencies

* A device with a Linux distribution

### Executing program

* The .sh file should be given executable permission.
```
chmod +x keylogger.sh
```
* Then it can be run via terminal.
```
./live_host_scanner.sh
```

### How the Project Works
The application consists of 2 different code files and 1 text document. These;
* keylogger.py
* keylogger.sh
* keymaps.txt

The main part that makes the application work is located in the Python file (keylogger.py). The part written in the BASH script allows the "showkey" function to be used, the recorded data to be sent using SMTP, and the application to be started with authorization.

The "keymaps.txt" text document, in which the keycodes of the keys on the keyboard are written in advance, is required for key tracking of the project.

It enables the python file to be run thanks to the codes in the written BASH script. There is no need to run the python file separately, everything happens automatically after the BASH script is run.

This project terminates itself if no terminal entry is made for 10 seconds.

## Data Transfer via SMTP
This method is designed to connect to google mail servers based on the scenario that the sender is a GMAIL account. To connect to Google's SMTP server easily using "Application Defined Password Method":

1. Go to https://myaccount.google.com/
2. Click the "Security" button in the left menu
3. In the "Sign in to Google" section, click "2-Step Verification".
4. You may be asked for your e-mail address and password again here.
5. Click on the "Application passwords" section at the bottom.
6. Give your application a name "Sending email over sockets using SMTP"
7. Click the "Create" button.
8. You can use the password displayed on the screen in your applications. (after encoding with base64)

The data transmission block we wrote in the BASH script is installed on the firewall on our device. Data transmission can be made if the necessary permissions are given.
In order for the project to work in a test-oriented manner without transmitting data, the data transmission block has been placed in the comment line. If desired, this block can be removed from the comment line, filled with the necessary information, the firewall can be set and run.

## Project Features

* This project can track successfully no matter what type of keyboard layout you use, other than the virtual keyboard.
* This project can successfully track special characters with a single key combination.
* This project can successfully track the alphabet characters on the keyboard (except for the letters "ö" and "ş").
* This project can successfully track the F keys on the keyboard.
* This project can successfully monitor whether the CapsLock and NumLock setting keys on the keyboard are on or off and track any changes.
* This project can track the arrow keys on the keyboard.
* This project can track Turkish characters other than "ş" and "ö" on the keyboard.
* This project can successfully track the NumLock number on the keyboard.

## Project Deficiencies

* This project cannot track special characters with multiple key combinations.
* This project cannot keep track of whether the letters of the alphabet entered into the terminal are uppercase or lowercase.
* This project cannot track keys via the virtual keyboard.

## Authors

[Muhammet Can Namli](https://www.linkedin.com/in/muhammet-can-naml%C4%B1-9556311b9/)


## Help
If you have suggestions and recommendations, please contact me.

## WARNING
This project was developed for educational purposes only. Before using this software, please consider the following points:

* Legal Authority: Check if you have legal authorization to use a keylogger.

* Privacy Principles: Respect others' privacy and avoid unauthorized usage.

* Notification and Consent: Obtain explicit consent from individuals before using a keylogger on their devices.

* Consequences: Non-compliance with laws can lead to serious consequences.

* Responsibility: Usage is entirely your responsibility and should not be for malicious purposes.

Always prioritize legal compliance and ethical behavior.
