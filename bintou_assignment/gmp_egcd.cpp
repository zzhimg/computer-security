#include <stdio.h>
#include <gmp.h>
#include <iostream>


using namespace std;

mpz_t gmp_egcd(mpz_t a,mpz_t b){
        mpz_t r0,r1,s0,s1,q,r;
	mpz_init_set_si(r0,1);
	mpz_init_set_si(r1,0);
	mpz_init_set_si(s0,0);
	mpz_init_set_si(s1,1);
	mpz_init_set_si(q,0);
	mpz_init_set_si(r,0);
	signed long int tmp=1;
	while(tmp){
	mpz_fdiv_qr(q,r,a,b);
	mpz_set(a,b);
	mpz_set(b,r);
	mpz_swap(r0,r1);
	mpz_submul(r1,q,r0);
	mpz_swap(s0,s1);
	mpz_submul(s1,q,s0);
	tmp = mpz_get_si(b);
	}
	return r0,s0,a;
}
