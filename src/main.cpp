#include <cstdlib>
#include <iostream>

#include <vector>
#include "libDEM/DEM.h"

using namespace std;

void generate(string ifname, string ofname) {
	cout << "\033[1;35mDigital Elevation Model\033[0m" << endl;
	DEM m;
	cout << "[  0%] \033[32mReading the file\033[0m" << endl;
	m.read(ifname);
	// cout << "[ 25%] \033[32mSearching minimum and maximum in data\033[0m" << endl;
	cout << "[ 35%] \033[32mTriangulation\033[0m" << endl;
    m.triangulation();
	cout << "[ 50%] \033[32mProcessing the data\033[0m" << endl;
	m.process();
	cout << "[ 75%] \033[32mSaving\033[0m" << endl;
	m.save(ofname, 100, 100);
	cout << "[ 75%] \033[32mDigital Elecation Model successfully generated\033[0m" << endl;
}

int main(int argc, char *argv[]) {
    
    // Reading the filename in parameters    
    if (argc < 2)
        cout << "Not enough arguments" << endl;

    else {
    	string ifname="";
    	string ofname="";

      	std::vector<std::string> Args(argv + 1, argv + argc);
      
      	for(std::size_t i = 0; i < Args.size(); ++i) {
        	if (Args[i].find("+name=") != std::string::npos)
          		ifname = Args[i].erase(0, 6);

        	if (Args[i].find("+out=") != std::string::npos)
          		ofname = Args[i].erase(0, 5);
    	}

      	if (ifname == "")
        	cout << "Specify a file name with the syntax : +name=filename" << endl;

     	else {
        	if (ofname == "")
          		ofname = ifname + "_map";

        	generate(ifname, ofname);
      	}
    }
    return EXIT_SUCCESS; 
}