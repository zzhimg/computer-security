#include <iostream>

using namespace std;

int gf_mul(int a,int b){
	int  result = a * ( b % 2);
	int  m = 27;
	int  tmp = a;
	b /= 2;
	while(b != 0){ 
		if( tmp*2 >= 256 ){
			tmp = tmp << 1;
			tmp ^= m;
			tmp ^= 256;
		} 
	else tmp = tmp  << 1 ;
	result = result ^ ( tmp * ( b%2 ) ); //b为奇数，则加，为偶数，则不加。
	b = b/ 2;
	}
	return result;
}

int gf_div_qr(int a,int b, int* r){
	int t1,t2,t;
	int result = 0;
	while( a >= b ){
	int n = 16;
		while( (a >> n)	% 2 == 0 ){
			n -= 1;
		}
		t1 = n;
		while( (b >> n) % 2 == 0 ){
			n -= 1;
		}
		t2 = n;
	t = t1 - t2 ;
	result += ( 1 << t) ;
	a = a ^(b << t);
	}
	*r = a ;
	return result;
}

int gf_egcd(int a, int b){
	int r0 = 1;
	int s0 = 0;
	int r1 = 0;
	int s1 = 1;
	int tmp = 0;
	int *r = &tmp;
	int q  = 0;
	while( b != 0){
		q = gf_div_qr(a,b,r);
		a = b  ;
		b = *r ;
		swap ( r0, r1 );
		r1 = r1 ^ gf_mul(q,r0);
		swap ( s0, s1 );
		s1 = s1 ^ gf_mul(q,s0);
	}
	return r0;
}
