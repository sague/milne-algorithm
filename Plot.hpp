#include <string>
#include <fstream>
#include <math.h>
#include <cstdlib>

using namespace std;


class Plot
{
private:
	ofstream gnuplot_file;
public:
	void generate(string file_name){
		gnuplot_file.open(file_name);
		gnuplot_file << "set terminal pdf\n";
		gnuplot_file << "set output 'out.pdf'\n";
		gnuplot_file << "set xlabel \"x_n\"\n";
		gnuplot_file << "set ylabel \"y_n\"\n";
		gnuplot_file << "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.7   # --- blue\n";
		gnuplot_file << "plot \"milne.dat\" with linespoints ls 1, \"runge_kutta.dat\" with linespoints ls 1 lc rgb '#FF0000', \"taylor.dat\" with linespoints ls 1 lc rgb '#00B41C' \n";

		gnuplot_file.close();

		Plot::show(file_name);
	}

	void show(string file_name){
		string cmd = "gnuplot " + file_name +";";
		system(cmd.c_str());

		system("exo-open out.pdf");
		system("gnome-open out.pdf");

		system("rm *.dat");
		system("rm *.gnu");
	}
};