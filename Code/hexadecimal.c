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
 * @fn unsigned int hexa_dec_rec(char*, int)
 * @brief Convertir un nombre hexadécimal en nombre décimal
 *
 * @pre @f$ \equiv (hexa \neq NULL) \wedge n > 0 , n \in \mathbb{N} ~\wedge~ hexa[0 \ldots  n-1] init ~\wedge~ hexa[0 \ldots  n-1] init \Rightarrow hexa ~ init @f$
 * @post @f$ \equiv (hexa\_dec\_rec)_{10} = Hexa\_Dec\_Rec(hexa, n)  \wedge hexa = hexa_0 \wedge n \neq n_0	 @f$
 * @param hexa, le nombre hexadécimal
 * @param n, le nombre de symboles dans le nombre hexadécimal
 * @return la représentation décimale du nombre hexadécimal.
 */
unsigned int hexa_dec_rec(char *hexa, int n) {
	assert(hexa);
	assert(n > 0);

	char *l_nextCase;
	unsigned int l_convert;
	unsigned int l_position;
	unsigned int l_decimal;
	unsigned int l_exposant;

	l_position = n - 1;
	l_nextCase = hexa + 1;
	l_convert = convert(*hexa);
	l_exposant = hexa_power(l_position);
	l_decimal = l_convert * l_exposant;

	if (n == 1)
		return (l_decimal);

	return (l_decimal + (hexa_dec_rec(l_nextCase, l_position)));
}
