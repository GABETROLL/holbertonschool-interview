#include "palindrome.h"

/**
 * is_palindrome - Converts
 * 'n' into its string form
 * to tell if 'n' is a palindrome or not.
 *
 * Uses 0 manual allocations.
 *
 * @n: number to evaluate
 * Return: 1 if 'n' is a palindrome in base 10,
 * 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char digits[21] = {0};
	/* the ULONG limit has 20 digits. */
	size_t digit = 0;
	size_t other_digit = 0;

	/*
	 * initialize 'digits' to be an array of 0's,
	 * except for the terminating null byte.
	 */
	for (; digit < 20; digit++)
		digits[digit] = '0';

	/*
	 * Convert 'n' into its string form, in 'digits'
	 */
	for (digit = 19; ; digit--)
	{
		digits[digit] = n % 10;
		n /= 10;

		if (digit == 0)
			break;
	}

	/*
	 * Compare the digits in 'digits'
	 * from the left and right
	 */
	while (digit <= other_digit)
	{
		if (digits[digit] != digits[other_digit])
			return (0);
	}

	return (1);
}

