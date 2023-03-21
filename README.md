# Inter Process Communication [Mini-Project]
**Goal**: The main goal of the app is the client generate a random number and based on that number the server will return an array with N length.
This project was developed in an academic context as a Unix project in order to help us understand interprocess communication better.
It implements a client-server communication system that uses :
- Named pipes
- TCP sockets
- UDP sockets. 
The server processes requests in parallel using fork(), and clients can be launched sequentially or in parallel too.

# Getting Started
To use this project, you need to have a Unix-like environment with a C compiler (such as GCC) installed. You can clone the repository to your local machine by running the following command:
```
git clone https://github.com/feriel214/Client-Server-Communcation.git
```
# Project Structure
The project consists of the following files:

- **tube_nomme**: The folder contains the implementation using Named pipes
- **socket_udp**: The folder contains UDP implementation
- **socket_tcp**: The folder contains TCP implementation
- **Makefile**: a Makefile to build the project
- **menu.c**  : The main menu to navigate between the different implementation
- **scriptTcp.sh** : contains the commands necessary to launch the mode of TCP communications
- **scriptTnomme.sh** : contains the commands necessary to start the communication client-server using named pipes
- **scriptUdp.sh** : contains the commands necessary to launch the mode of UDP communications

# Building the Project
To build the project, navigate to the project directory and run the following command:
```
make app 
```
This will compile the project and generate the executable files.

# Running the Project 
To run the project, navigate to the project directory and run the following command:
```
make run
```
This opens a GUI contains the main menu which integrates the different parts of the application
we choose the option we want to test by clicking on the appropriate button.
# 👀 More Information 
If you want to discover more details about the project, the links below contains respectively a report and set of test.
- 📌 Report :  https://drive.google.com/file/d/1qi0vJbftgrf9-BV3gDbNHwgaitBzVtoD/view?usp=share_link
- 📌 set of test doc : https://drive.google.com/file/d/14ulGhFE37tBcZhECpEbAIIHQuBgXQvaa/view?usp=share_link
# Contributing
If you want to contribute to this project, feel free to fork the repository and submit a pull request.
# ✨ Let’s Connect and Build Something Amazing Together
- Reach me out on LinkedIn: https://www.linkedin.com/in/feriel-zarrouki-1ba917186/

