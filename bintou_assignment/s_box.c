#include <iostream>
#include "galois_field.cpp"
using namespace std;

int main(){
	int s_box[16][16];
	int m = 283;
	int c = 99;
	for(int i=0;i<=15;i++){
		for(int j=0;j<=15;j++){
			s_box[i][j] = i*16+j;
			s_box[i][j] = gf_egcd(s_box[i][j],m);
			cout<<s_box[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	int matrix [8] = {241,227,199,143,31,62,124,248};
	int tmp[8]= {0};
	int mid,n,t = 0;
	for(int i=0;i<=15;i++){
		 for(int j=0;j<=15;j++){ // deal with each value saved in s_box.
                         t ^= t;
			 for(int k = 0;  k <= 7 ; k++){
				tmp[k] = (s_box[i][j] & matrix[k]);  //tmp[k] saved the value of the AND operation
			       					    //	of matrix[k] and the bits of s_box[i][j].
				mid = ( tmp[k] & 1 );  	   // initialize mid with the first bit of tmp[k].
				n = 7;
		       		while(n){ //compress tmp[k] into a single bit and save it as the first bit of mid.
					if( (tmp[k]>>n) & 1  == 1) //check the bits of tmp[k] one by one.
						mid ^= 1; 
					else 	mid ^= 0;
					n -= 1;
				}
				tmp[k] = mid ^( (c>>k) & 1 ); // XOR with the bits of value 99.
				t += (tmp[k] << k ); 	      // construct the value of s_box[i][j] with tmp[0]~tmp[7]
			}	
			s_box[i][j] = t ;
			cout<<s_box[i][j]<<"\t";
                }
		 cout<<endl;
       	}
	//以上为构建s_box
	//以下为s_box构建字符映射
	char a,b;
	a = cin.get();
	b = cin.get();
	int row,col=0;
	if (b<=57) col = b-48;
	else col =  b-55;
	if (a<=57) row = a-48;
	else row = a-55;
	cout<<row<<col;
	int output = s_box[row][col];
	b = (output % 16);
	a = (output >> 4) % 16;
	if( b > 9)
		b += 55;
	else 	b += 48 ;
	if( a > 9)
		a +=55;
	else	a +=48;
	cout<<a<<b;
	return 0;
}
