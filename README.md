# Labs from Technology of Distributed systems

## Building the Repository
The build depends on *Git* and *GCC*. Also, it's needed to install required utils and libs such as *make*, *OpenMP* and *MPICC*. Once the prerequisites are installed, the build is simply a matter of invoking 'make' command at the root folder of specified lab.

The details of installing the components differ depending on the operating system. See the following pages based on your current OS.

* [Windows Build Instructions](#windows-build-instructions)
* [Linux Build Instructions](#linux-build-instructions)

### Windows Build Instructions
#### Git
For actual user operations, it is convenient to use Git. You can get it from
* Install [Git For Windows](https://git-for-windows.github.io/)
* Add its location (e.g. C:\Program Files\Git\cmd) to the PATH environment variable.
The installation script has a checkbox to do this, but you can do it yourself after the fact following the instructions at [Adding to the Default PATH variable](#adding-to-the-default-path-variable)

#### GCC and OpenMP
As Windows hasn't built-in gcc compiler, it's required to install MinGW (Minimalist GNU for Windows)

1. Download MinGW installer from [here](http://www.mingw.org/download/installer?)
2. Run `mingw-get-setup.exe` to start the installer
3. Peruse the `blurb` of the opening dialogue, then click the Install button, to proceed with the installation
4. Review the installation options, as presented in the following dialogue. If you wish to change the installation directory, from the `C:\MinGW` offered by default, do please observe the warnings above, and reiterated within the dialogue, relating to path names with embedded spaces. Note that the CLI variant of mingw-get is always installed; the GUI variant is also installed by default, (and is highly recommended), but you may exclude it if you wish. It is recommended that you **DO NOT** select an `All Users` installation.
5. When you have set the installation options to suit your preferences, click the Continue button to initiate the download and installation of mingw-get itself.
6. Run `MinGW Installation Manager` from the Start Menu or from location folder
7. Select `Basic Setup` in the left hand (tree view) pane, to expose the package you wish to manage within the upper right hand (list view) pane
8. Right click on `mingw32-base` and select `Mark for Installation`
9. Switch to All Packages -> MinGW -> MinGW Base System -> MinGW Standard Libraries and select `mingw32-libpthreadgc` and `mingw32-pthreads-w32` with class `dev`
10. When you have completed selection and marking, open the `Installation` menu (on the menu bar) and select the `Apply Changes` operation
11. Review the schedule of pending actons, then click `Apply` button
12. After the installation completes, open Windows Command Line (cmd.exe), type `%PATH_TO_MINGW%\bin\mingw32-make.exe %PATH_TO_MINGW\bin\make.exe` where `%PATH_TO_MINGW%` - your path to MinGW root folder (e.g. `C:\MinGW`) and press Enter. You should see the result `1 file(s) copied`
13. Add %PATH_TO_MINGW%\bin folder to the PATH environment variable. For the details, see [this](#adding-to-the-default-path-variable)

#### MPICH
You would also need to install MPICH to the machine.

1. First of all, you need to download Microsoft MPI from the [official site](https://www.microsoft.com/en-us/download/details.aspx?id=55991)
2. Run `MSMpiSetup.exe` and `msmpisdk.msi` and follow the instructions

#### Adding to the default PATH variable
The commands above need to be on your command lookup path. Some installers will automatically add them to the path as part of installation, but if not here is how you can do it.

You can of course add a directory to the PATH environment variable with the syntax

`set PATH=%PATH%;DIRECTORY_TO_ADD_TO_PATH`

However the change above will only last until the command windows closes. You can make your change to the PATH variable persistent by going to Control Panel -> System And Security -> System -> Advanced system settings -> Environment Variables, and select the 'Path' variable in the 'System variables' (if you want to change it for all users) or 'User variables' (if you only want to change it for the currnet user). Simply edit the PATH variable's value and add the directory (with a semicolon separator).

### Linux Build Instructions
#### Git
If you are using RPM-based distributive such as Fedora, CentOS or RHEL, you can use `dnf`: 

`$ sudo dnf install git-all` 

If you're on a Debian-based distro like Ubuntu, try `apt-get`: 

`$ sudo apt-get install git-all` 

For more options, there are instructions for installing on several different Unix flavors on Git [website](http://git-scm.com/download/linux) 

#### GCC and OpenMP
Many Linux distros already have gcc installed. To check this out, try `gcc -v`. You should see output like `gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1-16.04.5)`

If your distro has not gcc installed, follow the instruction:

On Debian-based distributives, try `$ sudo apt install build-essential`

## Using Your Build

