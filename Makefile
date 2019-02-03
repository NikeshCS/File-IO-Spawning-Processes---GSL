dealer: dealer.c
		gcc dealer.c -o dealer
hand: hand.c
		gcc -I$$HOME/local/gsl-2.5/include hand.c -o hand -lgsl -lgslcblas -L$$HOME/local/gsl-2.5/lib
pitboss: pitboss.c
		gcc pitboss.c -o pitboss