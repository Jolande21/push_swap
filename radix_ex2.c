/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_ex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:06:25 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/15 12:40:49 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Radix Sort in C Programming

#include <stdio.h>

// Function to get the largest element from an array
int getMax(int array[], int n) 
{
  int max;
  int i;  
  
  // set the max value to the first element of the array
  max = array[0];

  // check for every element of the array if it is greater than the element before
  // if it is greater, then this is the new max
  i = 1;
  while (i < n)
  {
    if (array[i] > max)
      max = array[i];
    i++;
  }
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void	countingSort(int array[], int size, int place) 
{
  int output[size + 1];
  int max;
  int i;
  

  // look for the max in the current digit position 
  printf("counting sort array[0]: %d\t place: %d\n", array[0], place);
  max = (array[0] / place) % 10;
  printf("counting sort max before: %d\n", max);
  
  i = 1;
  while (i < size) 
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
    i++;
  }
  printf("counting sort max after: %d\n", max);

  int count[max + 1];
  // fill the count array with zero
  i = 0;
  while (i < max)
  {  
    count[i] = 0;
    i++;
  }
  printf("the count array size: %d\n", i);

  // Calculate the number of times the digit occurs 
  // put it in the count array
  i = 0;
  while (i < size)
  { 
    count[(array[i] / place) % 10]++;
    i++;
  }  
  
  i = 0;
  printf("the norml count array: ");
  while (i < size)
    printf("%d\t", count[i++]);
  printf("\n");
  
  // Calculate cumulative count
  i = 1;
  while (i < 10)
  {
    count[i] += count[i - 1];
    i++;
  } 
  
   i = 0;
  printf("the cumul count array: ");
  while (i < size)
    printf("%d\t", count[i++]);
  printf("\n");
  
  // Place the elements in sorted order in the output array
  // stel size = 7; start van index = 7 - 1 = 6
  i = size - 1;
  while (i >= 0) 
  {
    printf("index of loop: %d\n", i);
    printf("counting sort array[i]: %d\t calculated in count index: %d\n", array[i], (array[i] / place) % 10);
    printf("the count value: %d\n", count[(array[i] / place) % 10]);
    output[count[(array[i] / place) % 10] - 1] = array[i];
    printf("the index of the output array: %d\n", count[(array[i] / place) % 10] - 1);
    count[(array[i] / place) % 10]--;
    i--;  
  }

  i = 0;
  printf("the output array: ");
  while (i < size)
    printf("%d\t", output[i++]);
  printf("\n");
  
  i = 0;
  while (i < size)
  {
    array[i] = output[i];
    i++;
  }
}

// Main function to implement radix sort
void  radixsort(int array[], int size) 
{
  int max;
  int place;
  
  // Get maximum element to know how many digit positions you need to check
  max = getMax(array, size);

  // Apply counting sort to sort the digit for every digit position
  place = 1;
  while ((max / place) > 0)
  {
    countingSort(array, size, place);
    place *= 10;
  }
}

// Print an array
void  printArray(int array[], int size) 
{
  int i;

  i = 0;
  while (i < size) 
  {
    printf("%d  ", array[i]);
    i++;
  }
  printf("\n");
}

// Driver code
int main(void) 
{
  //              0     1    2   3  4   5   6
  int array[] = {1014, 1677, 1840, 2213, 2835, 3362, 3396, 3701, 3733, 4400, 4725, 4798, 5507, 5560, 6922, 7008, 8208, 9387, 9538, 9953};
  int n = sizeof(array) / sizeof(array[0]);
  printf("the size of the example array: %d\n", n);
  radixsort(array, n);
  printArray(array, n);
}