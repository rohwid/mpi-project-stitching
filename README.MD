## About

Stitching process with OpenCV using mpi to parallel the process.

## Installing gcc and g++
This project using C/C++ programming language, so you need to compile using gcc/g++

    $ sudo apt-get install gcc g++

## Installing OpenCV

Just execute `./install_opencv` file to install OpenCV automatically in your device.

## Installing MPI

Just execute `./install_opencv` file to install OpenCV automatically in your device.

## Test Program

It's only a testing the OpenCV, is OpenCV run or not in your computer. It will be load and show the `Lenna.png`, but this program won't run in non-GUI operating system because the GUI is required.

    $ cd test
    $ make all

## Stitching Program

Open directory `./stitching` to open the stitching program. It write using C++ with [OpenCV Library] (http://opencv.org/).

Run the program:

    $ cd stitching
    $ make all

## Parallel Stitching
Open directory `./parallel-stitch` to open the parallel stitching program and follow this step to compile and run.

+ Compile the project first:

        $ cd parallel-stitch
        $ make all

+ To run the project in multiple nodes and set the number of processes. You must follow this [step first](http://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/), to setup the NFS and synchronize all the nodes.

+ Copy executable file (ex: `stitch`) to nfs directory (ex: `cloud`) to sync with all nodes after install NFS and sync all the nodes:

        $ cp stitch ~/cloud

+ Determine the host which wanna compile the `stitch` program on file `./host_file_virt`.

        $ ./exec-multi host_file_virt stitch
