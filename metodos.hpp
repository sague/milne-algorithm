class Metodos
{
private:
	double x, y, h, n;
	double x_global, y_global;
	ofstream salida_plot;
public:
	Metodos(double x_, double y_, double h_, double n_) :
			x(x_), y(y_), h(h_), n(n_) {
				x_global = x;
				y_global = y;
			}
	

	void milne(){
		int i;
		double c,x1,x2,x3,x4,y1,y2,y3,yp,yc,f0,f1,f2,f4,error;

		salida_plot.open("milne.dat");


		cout<<"\nPara Milne necesito tres soluciones: "<<endl;

		cout <<"\n Ingrese y(1) en x= "<<(x+h)<<": " <<endl; 
		cin>>y1;

		cout <<"\n Ingrese y(2) en x= "<<(x+2*h)<<": " <<endl;
		cin>>y2;

		cout <<"\n Ingrese y(3) en x= "<<(x+3*h)<<": " <<endl;
		cin>>y3;
		cout<<endl;

		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\tM É T O D O    D E    M I L N E - S I M P S O N " <<endl;
		
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\tXn"<<"\tPredicción: Y*(n+1)" <<"\t Corrección: Y(n+1) " <<"\t Error "<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;



		for (i=0; i<n; i++){ 

			
			f0 = func((x+3*h), y3);
			f1 = func((x+2*h), y2);
			f2 = func((x+h), y1);

			yp = y + (4*h/3)*(2*f0 - f1 + 2*f2);

			f4 = func((x+4*h), yp);

			yc = y2 + (h/3)*(f1 + 4*f0 + f4);
				
			error = fabs(yc-yp);
			f0 = func((x+3*h), y3);
			
			cout<<"\t"<<x+4*h<<"\t\t" <<yp<<"\t\t" <<yc <<"\t\t\t" <<error <<endl;

			// guarda el archivo para luego plotearlo
			salida_plot << 	x+4*h << " " << yc << endl;

			y=y1;
			y1=y2;
			y2=y3;
			y3=yc;

			x += h;

		}

		salida_plot.close();
	}

	void runge_kutta(){
		int i;
		double k1, k2, k3, k4;
		double x = x_global;
		double y = y_global;


		salida_plot.open("runge_kutta.dat");

		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\tM É T O D O    D E    R U N G E - K U T T A " <<endl;
		
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\tXn"<<"\tYn"<<endl;

		for(i= 0; i<n; i++){


			k1 = h*func(x,y);
			k2 = h*func((x + h*0.5), (y + k1*0.5));
			k3 = h*func((x + h*0.5), (y + k2*0.5));
			k4 = h*func((x + h), (y + k3));


			y= y + (k1 + 2*k2 + 2*k3 + k4)/6;
			x +=h;


			cout<<"\t"<<x<<"\t" <<y <<endl;

			salida_plot << x << " " << y << endl;

		}

		salida_plot.close();
	}

	void taylor(){
		int i;
		double a, b;
		double x = x_global;
		double y = y_global;

		salida_plot.open("taylor.dat");


		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\tM É T O D O    D E    T A Y L O R " <<endl;
		
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\tXn"<<"\tYn"<<endl;

		for(i=0 ; i<n; i++){

			a = func(x,y);
			b = fdev(x,y);

			y = y + (h*a + h*h*b/2);
			x += h;

			cout<<"\t"<<x<<"\t"<<y<<endl;

			salida_plot << x << " " << y << endl;
		}

		salida_plot.close();
	}

};