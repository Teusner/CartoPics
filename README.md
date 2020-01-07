# CartoPics

CartoPics is a simple script to generate Digital Elevation Model picture.

<p align="center">
    <img src="https://github.com/Teusner/CartoPics/blob/master/example/brest.png"> <br>
    <em>Raster of a Brest's harbour area</em>
</p>

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Let's get started ! Clone the repository using git

```bash
git clone https://github.com/Teusner/CartoPics
```

### Compiling

You are now able to compile the project

```bash
cd CartoPics/src
mkdir build
cd build
cmake ..
make
```

create_raster is now generate in Cartopics/src/build

### First example

To generate a Digital Elevation Model, you should have a file of the points you measured, as you can see on the following example

```
# latitude    longitude  elevation
48.29762887 -004.41737340 14.334
48.29762971 -004.41735997 14.379
48.29763698 -004.41738809 14.452
...
```
And then, run CartoPics with the name of your file in parameter and the number of pixel along the x-axis

```bash
./cartopics my_file.txt 1000
```

You can find your output image in the same directory with the name *my_file_map.ppm*

## Running the tests

To run the test, you need first to compile the project. Then you are able to run *ctest* in the build path.
```bash
cd build
ctest
```

You can too run verbose tests to have more informations about the tests.

```bash
ctest --verbose
```

## Read The Docs

A documentation of the modules used is available in the documentation folder. You can show the html page which was generated with *Doxygen* with :

```bash
firefox documentation/index.html
```

## Built With

* [delaunator-cpp](https://github.com/delfrrr/delaunator-cpp) - An efficient delaunay triangulation library
* [Spectrum](https://github.com/richardroberts1992/Spectrum) - A ColorMap generator [PDF Description](http://cs.swan.ac.uk/~csbob/research/callCenter/color/roberts18spectrum.pdf)

## Authors

* **Brateau Quentin** - *Initial work* - [Teusner](https://github.com/Teusner) :sunglasses:

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details
