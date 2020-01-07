#include <cstdlib>
#include <iostream>
#include <sstream>

#include <vector>
#include <ctime>

#include <DEM.hpp>

using namespace std;

void time_stamp(time_t &t0, time_t &t1, string &time) {
	int t = t1 - t0;

	int min = int(t/60);
	int sec = int(t - min*60);

	ostringstream s;
	s << "\033[38m";
	if (t < 600)
		s << "[0" << min << ":";
	else
		s << "[" << min << ":";
	if (sec < 10)
		s << "0" << sec << "]";
	else
		s << sec << "]";	
	time = s.str();
}

void generate(string ifname, string ofname, int x) {
	time_t t0;
	time_t t1;
	string time_str;
	time(&t0);

	cout << "\033[1;35mDigital Elevation Model\033[0m" << endl;
	DEM m(ifname, ofname, x);
	time_stamp(t0, t0, time_str);
	cout << time_str << " \033[32mReading the file\033[0m" << endl;
	m.read(ifname);

	time(&t1);
	time_stamp(t0, t1, time_str);
	cout << time_str << " \033[32mTriangulation\033[0m" << endl;
    m.triangulation();

	time(&t1);
	time_stamp(t0, t1, time_str);
	cout << time_str << " \033[32mProcessing the data\033[0m" << endl;
	m.process();

	time(&t1);
	time_stamp(t0, t1, time_str);
	cout << time_str << " \033[32mSaving\033[0m" << endl;
	m.save(ofname, 100, 100);

	time(&t1);
	time_stamp(t0, t1, time_str);
	cout << time_str << " \033[32mDigital Elevation Model successfully generated\033[0m" << endl;
}

int main(int argc, char *argv[]) {
    // Reading the filename and the image size in parameters    
    if (argc < 3)
        cout << "Not enough arguments ! Please specify the filename and the image size in arguments" << endl;

    else {
    	string ifname = argv[1];
    	string ofname = argv[1];
		size_t point_pos = ofname.find("."); 
    	if (point_pos != string::npos) 
			ofname.erase(ofname.rfind('.'));
		ofname += ".ppm";

		int size = std::stoi(argv[2]);

		generate(ifname, ofname, size);   	
    }
    return EXIT_SUCCESS; 
}