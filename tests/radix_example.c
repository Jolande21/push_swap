/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_example.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:42:11 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/14 17:55:45 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
    int mx;
	int	i;
	
	mx = arr[0];
	i = 1;
    while (i < n)
	{
        if (arr[i] > mx)
			mx = arr[i];
		i++;
	}
	printf("The maximum int in the array is: %d\n", mx);
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int arr[], int n, int exp)
{

    // Output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
	{
		printf("the value at arr[i]: %d\n", arr[i]);
		printf("the exp: %d\n", exp);
		printf("the count array index: %d\n", (arr[i] / exp) % 10);
        count[(arr[i] / exp) % 10]++;
		printf("the value at count[i]: %d\n", count[(arr[i] / exp) % 10]);
	}

	i = 0;
	while (i < 10)
		printf("%d\t", count[i++]);
	printf("\n");
	
    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
	{
		printf("the value of count[i] before: %d\n", count[i]);
        count[i] += count[i - 1];
		printf("the value of count[i] after: %d\n", count[i]);
	}
	
	i = 0;
	while (i < 10)
		printf("%d\t", count[i++]);
	printf("\n");

    // Build the output array
    for (i = n - 1; i >= 0; i--) 
	{
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(int arr[], int n)
{

    // Find the maximum number to
    // know the number of digits
    int m = getMax(arr, n);

	printf("The maximum int in the radixsort function: %d\n", m);
	
    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
	{
		printf("n: %d\texp: %d\n", n, exp);
        countSort(arr, n, exp);
	}
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver Code
int main()
{
    int arr[] = { 543, 986, 217, 765, 329 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
