 
 #include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;


int a = 0  , b = 0;


std::vector<std::vector<int> > sorty (500, std::vector<int> (500));
std::vector<std::vector<int> > circles(500, std::vector<int> (500));


void sortArr(int arr[], int n) 
{ 
	b = 0;

     // Vector to store element 
    // with respective present index 
    vector<pair<int, int> > vp; 
  
    // Inserting element in pair vector 
    // to keep track of previous indexes 
    for (int i = 0; i < n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    } 
  
    // Sorting pair vector 
    sort(vp.begin(), vp.end()); 
  
    // Displaying sorted element 
    // with previous indexes 
    // corresponding to each element 
    cout << "Element\t" 
         << "index" << endl; 
    for (int i = 0; i < vp.size(); i++) {
    

    	//cout << "passed\t" << a << "  " << b << endl;
    	sorty[a][b] = vp[i].first;
    	circles[a][b] = vp[i].second + 1;		
        cout << vp[i].first << "\t"
             << vp[i].second  << endl;
             ++b;

    } 
    	a++;

} 

int main(){


	// ifstream inFile;
	// inFile.open("lsdfdssdf.txt");
  
	// if (!inFile) {
 	//    cerr << "Unable to open file datafile.txt";
 	//    exit(1);   // call system to stop
	// }


	int n, p;

	cin >> n;
	cin >> p;
 
	int x[n];
	int y[n];
	int z[n];
	
	// cin >> p;

	vector<int> facilities[n];
	for(int i = 0 ; i < n ; i++){
		cin >>x[i];
		cin >>y[i];
		cin >>z[i];
		// facilities[i]. push_back(x[i]);
		// facilities[i]. push_back(y[i]);
		// facilities[i]. push_back(z[i]);

	}

	for(int i = 0 ; i < n ; i++){
		facilities[i]. push_back(x[i]);
		facilities[i]. push_back(y[i]);
		facilities[i]. push_back(z[i]);

	}


	int d[n][n];
	int radius[n][n];

	for( int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			d[i][j] =  sqrt(pow(x[i] - x[j], 2) +  
                pow(y[i] - y[j], 2) +  
                pow(z[i] - z[j], 2) * 1.0);;
		}
	}


	for(int i = 0; i < n; i++ ){
	int arr[n];
		for(int j = 0 ; j < n; j++){	


		arr[j] = d[i][j];	
		
		}
		//cout << "Function called" << endl;
		sortArr(arr, n);
	}

	// cout << "The D sorted matrix is -->" << endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			cout << sorty[i][j] << " ";  
			//cout << circles[i][j];
		}
		cout << endl;
	}	

	// cout << "----------------------" << endl;

	// cout << "The D circles matrix is -->" << endl;

	for( int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			//cout << sorty[i][j] ;
			// cout << circles[i][j]  << " ";
		}   
		cout << endl;
	}

	// cout << "----------------------" << endl; 
 
	//------------D radius ------------

	int k = 0 ;
	int maxi[n];
    
	for (int i = 0; i < n; ++i){
 		 maxi[i] = 0;
	}

	while(k < n){
		for(int i = 0 ; i < n; i++){

			int count = 0;
			for(int j = 0 ; j < n ; j ++){

				if( i != j && (d[k][i]>d[k][j])){
					count ++;
				}	
			}
			radius[k][i] = count;
		
			if(i == k ){
				radius[k][i] = 1;
			}
			if(maxi[k] <= count){
				maxi[k] = count;
			}
		}

		k++;
	}	 
	// cout << "The D radius matrix is -->" << endl;

	for( int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			//cout << sorty[i][j];
			// cout << radius[i][j]  << " ";
		}
		cout << " The max for the row is ----> " << maxi[i]<<  "      ";
		cout << endl;
	}	

	cout << "Initial solution" << endl;
	// int sol[p];

	// for(int i = 0 ; i < q ; i++){
	// 	sol[i] = rand() % 200;
	// 	cout << sol[i] << "-------" << endl;
	// }

	// Neighbouring solution generation	
	// // new center

	int first_center = 15;
	cout << "First Random Center   " << first_center << endl;  

	cout<< facilities[first_center][0] << endl;
	cout<< facilities[first_center][1] << endl;
	cout<< facilities[first_center][2] << endl;

	std::vector<int> initial_center;
	initial_center.push_back(first_center);
	
	int center = first_center;	
	for(int j =0 ; j < p - 1 ; j++){
		int cd = 0;

		for(int i = 0 ; i < n; i++){
		if(radius[center][i] > cd){
			cd = i;
			}
		}

			cout << "Critical distance point is -- >" << cd << endl; 

			cout << radius[cd][center] << endl;


			int jnew = (rand() + 1) %  radius[cd][center];
			cout << jnew << endl;
			int next_center = circles[cd][jnew];
			cout << next_center << endl;
			initial_center.push_back(next_center);
			cout << "Critical Distance is --> " << d[cd][center] << endl;
			center = next_center;
	}

	for(int i = 0 ; i < p; i++){
		cout << "P Centers are" << endl;
		cout << initial_center[i] << endl;
	}

	// Adding the solutions
	std::vector<int> new_centers;
 	new_centers = initial_center;
	int q;


	if(5*p < n){
		q = p/2;
	}
	else { 
		q = p/5;
	}


	int last_center = initial_center[p - 1];	

	for(int j =0 ; j < q ; j++){
		int cd = 0;
		for(int i = 0 ; i < n; i++){
		if(radius[center][i] > cd){
			cd = i;
		}
	   }
		

			cout << "Critical distance point is -- >" << cd << endl; 
			cout << "Center" << center << endl;
				cout << radius[cd][center] << endl;  
 


			int jnew = (rand() + 1) %  radius[cd][center];
			cout << jnew << endl;
			int next_center = circles[cd][jnew];
			cout << next_center << endl;
			new_centers.push_back(next_center);


			cout << "Critical distance is --> " << d[cd][center] << endl;
			center = next_center;

		}

		cout << p << "   " << q <<  "   " << new_centers.size() << endl;

	// Removing the q solutions iteratively

	return 0;

}