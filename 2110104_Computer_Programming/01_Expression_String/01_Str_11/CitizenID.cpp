#include <iostream> 
#include <cmath>
 
using namespace std; 
 
int main() { 
    
    string in;
    long long n12;

    cin >> in;

    n12 = (11 - ((13*(in[0] - '0')) + 12*(in[1] - '0') + 11*(in[2] - '0') + 10*(in[3] - '0') + 9*(in[4] - '0') + 8*(in[5] - '0') + 7*(in[6] - '0') + 6*(in[7] - '0') + 5*(in[8] - '0') + 4*(in[9] - '0') + 3*(in[10] - '0') + 2*(in[11] - '0')) % 11) % 10;

    cout << in.substr(0, 1) << "-" << in.substr(1, 4) << "-" << in.substr(5, 5) << "-" << in.substr(10, 2) << "-" << n12 << "\n";
    
}