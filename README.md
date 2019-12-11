# CartoPics

CartoPics is a simple script to generate an image based on a Digital Elevation Model.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

Let's get started ! Clone the repository using git :

```
git clone https://github.com/Teusner/CartoPics
```



### Compiling

You are now able to compile the project

```
cd CartoPics/src/build
cmake ..
make
```

CartoPics is generate in Cartopics/src/build

### First example

To generate a Digital Elevation Model, you should have a file of the points you measured, as you can see on the following example

```
# latitude    longitude  elevation
48.29762887 -004.41737340 14.334
48.29762971 -004.41735997 14.379
48.29763698 -004.41738809 14.452
...
```
And then, run CartoPics with the name of your file in parameter

```
./cartopics +name=my_file
```

You can find your output image in the same directory with the name *my_file_map*

## Parameters

Here is a comprehensive list of the parameters for CartoPics

Parameter   | Description  | Optionnal | Note
------------|--------------|-----------|----------
+name       | Specify the name of the input file | False
+out        | Specify the name of the output file | True | The default name is *my_file_map*
+verbose    | Specify if you want verbose output | True 

## Running the tests

Explain how to run the automated tests for this system


## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [delaunator-cpp](https://github.com/delfrrr/delaunator-cpp) - An efficient delaunay triangulation library
* [Spectrum](https://github.com/richardroberts1992/Spectrum) - A ColorMap generator

## Authors

* **Brateau Quentin** - *Initial work* - [Teusner](https://github.com/Teusner)

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details
