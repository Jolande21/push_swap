/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:30 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 15:27:49 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


vector<int> input;//parse the numbers into input ...

//reminder : there is no duplicatevector<int> copy = input; // copy the numbers from inputsort(copy.begin(), copy.end());for(int i = 0 ; i < input.size() ; ++i) 
    for(int j = 0 ; j < copy.size() ; ++j)
        if (input[i] == copy[j])
            input[i] = j;//put input into stack a .../*

/*

Remark : This is actually not the most efficient way to implement them. 
If you want a more efficient program, please learn about binary search or unordered_map (hash)
*/

