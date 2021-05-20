/**
 * @file hexadecimal.c
 * @brief Ce fichier contient les fonction permettant de convertir un hexadécimal en décimal
 *
 * @author Smeers Timothy S200930
 * @version 0.1
 * @date 17/05/2021
 *
 * Critère de style :
 * s_	Les variable globale à plusieurs fichiers
 * p_	Les paramètre de fonctions
 * l_	Les variables globale à une seule fonction
 */

#include "hexadecimal.h"

#include <assert.h>

#define HEXA_BASE 16

/**
 * @fn static unsigned int convert(char hex)
 * @brief Conversion entre un symbole hexadécimal et son équivalent décimal
 *
 * @param hex, le symbole hexadécimal
 *
 * @return la représentation décimale du symbole hexadécimal.  -1 en cas d'erreur.
 */
static unsigned int convert(char hex) {
	switch (hex) { /* @suppress("Missing default in switch") */
	case '0':
		return (0);
	case '1':
		return (1);
	case '2':
		return (2);
	case '3':
		return (3); /* @suppress("Avoid magic numbers") */
	case '4':
		return (4); /* @suppress("Avoid magic numbers") */
	case '5':
		return (5); /* @suppress("Avoid magic numbers") */
	case '6':
		return (6); /* @suppress("Avoid magic numbers") */
	case '7':
		return (7); /* @suppress("Avoid magic numbers") */
	case '8':
		return (8); /* @suppress("Avoid magic numbers") */
	case '9':
		return (9); /* @suppress("Avoid magic numbers") */
	case 'A':
		return (10); /* @suppress("Avoid magic numbers") */
	case 'B':
		return (11); /* @suppress("Avoid magic numbers") */
	case 'C':
		return (12); /* @suppress("Avoid magic numbers") */
	case 'D':
		return (13); /* @suppress("Avoid magic numbers") */
	case 'E':
		return (14); /* @suppress("Avoid magic numbers") */
	case 'F':
		return (15); /* @suppress("Avoid magic numbers") */
	}
	return (-1);
}

/**
 * @fn unsigned int puissance(unsigned int)
 * @brief Permet de faire un exposant d'une base 16 (16 ** p_exp)
 *
 * @pre /
 * @post /
 * @param p_exp l'exposant
 * @return unsigned int l_result Le resultat de l'exposant 16 ** p_exp
 */
static unsigned int hexa_power(unsigned int p_exp) {

	unsigned int l_result;

	l_result = 1;

	while (p_exp >= 1) {
		l_result *= HEXA_BASE;
		p_exp--;
	}
	return (l_result);
}

/**
 * @fn unsigned int size_char(char*)
 * @brief Permet de trouvé la taille d'un string
 *
 * @pre /
 * @post /
 * @param p_hexa le string dont il faut trouver son nombre de charactère
 * @return unsigned int i la taille du string
 */
static unsigned int size_char(char *p_hexa) {

	unsigned int i;
	i = 0;

	while (p_hexa[i])
		i++;

	return (i);
}

/**
 * @fn unsigned int hexa_dec_rec(char*, int)
 * @brief Convertir un nombre hexadécimal en nombre décimal
 *
 * @pre @f$ \equiv (hexa != NULL) \wedge n > 0 , n \in \mathbb{N}
 \\ \wedge (n = \mid \{hexa[0] - hexa[n]\}\mid) \Rightarrow (\{hexa[0],\ldots,hexa[n-1]\} \in \{0, \ldots, 9,A,\ldots,F \}
 \\ \wedge (hexa[n] = \backslash0)) @f$
 * @post @f$\equiv N = \sum_{i=0}^{n-1} a_i \times b^i , a_i \in \{0,1,\ldots,b-1\} \wedge N \in (\mathbb{N})_{10} @f$
 * @param hexa, le nombre hexadécimal
 * @param n, le nombre de symboles dans le nombre hexadécimal
 * @return la représentation décimale du nombre hexadécimal.
 */
unsigned int hexa_dec_rec(char *hexa, int n) {
	assert(hexa);
	assert(n > 0);

	unsigned int l_size;
	unsigned int l_convert;

	l_size = size_char(hexa);
	l_convert = convert(hexa[0]);

	assert(n == l_size);
	assert(l_convert != -1);

	unsigned int l_position;
	unsigned int l_decimal;
	unsigned int l_exposant;
	char *l_nextCase;

	l_position = n - 1;
	l_nextCase = hexa + 1;
	l_exposant = hexa_power(l_position);
	l_decimal = l_convert * l_exposant;
//	printf("l_convert : %d\n", l_convert);
//	printf("l_exposant : %d\n", l_exposant);
//	printf("l_decimal : %d\n", l_decimal);

	if (n == 1)
		return (l_decimal);
	print_stack_trace();
	return (l_decimal + (hexa_dec_rec(l_nextCase, l_position)));

}
