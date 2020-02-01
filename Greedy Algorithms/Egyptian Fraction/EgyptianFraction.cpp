#include <iostream>

using namespace std;

void egyptianFraction(int nr, int dr)
{
	if(nr==0 || dr==0 )
		return;

	if (dr%nr == 0) 
    { 
        cout << " 1/" << dr/nr; 
        return; 
    }
    if (nr%dr == 0) 
    { 
        cout << nr/dr; 
        return; 
    }
    if (nr > dr) 
    { 
        cout << nr/dr << " + "; 
        egyptianFraction(nr%dr, dr); 
        return; 
    }
    int n = dr/nr + 1; 
    cout << "1/" << n << " + "; 
  
    // Recur for remaining part 
    egyptianFraction(nr*n-dr, dr*n); 
}

int main(int argc, char const *argv[])
{
	int nr, dr;
	cout<<"enter nr and dr: ";
	cin>>nr>>dr;

	egyptianFraction(nr,dr);
	return 0;
}