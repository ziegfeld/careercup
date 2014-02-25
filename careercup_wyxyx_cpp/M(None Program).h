//Q: how can you efficiently implement the find and replace function for a string

//A: suffix tree is the best solution. Refer the following link:
//http://marknelson.us/1996/08/01/suffix-trees/
/*************************************************************************************************************************************/

//Q: . Carefully see the following transition from one word to other-
//PAN -> PEN -> MEN -> MET
//Here each word is achieved by changing any one character in previous word. 
//Now you are given with a Source word (PAN here) and a Destination word (MET here) and need 
//to find out shortest transition chain following above rule using only meaningful words. Dictionary 
//containing thousands of meaningful words is provided to you. WAP for this.

//A: Firstly, we go preprocessing for the whole words with in the dictionary which mean to build 
//translation graphs. The we can use graph search to find the translation steps from
// one word to another word. We can do the preprocessing by load the words one by one, for the nth word 
// which is about to be processed, we compare this word with other already processed words with the same length to
// see wether they can be transfered to each other. If it can, we add this word to the translation graph dealing with.
/*************************************************************************************************************************************/

//Q: A person can take one or two steps at a time to reach a particular floor( say in a building). 
//How many different ways can a person reach the nth floor? google

//A: Fibonacle
/*************************************************************************************************************************************/

//Q: There is an array of 52 numbers ? How do you shuffle this array ?
//Whats the complexity of your algorithm ? 
//What are the possible test cases ? 
//How do you change the design and or code if this program is used by a house wife or casino?

//A: Shuffling algorithms

//In a computer, shuffling is equivalent to generating a random permutation of the cards. 
//There are two basic algorithms for doing this, both popularized by Donald Knuth. 
//The first is simply to assign a random number to each card, and then to sort the cards in order of their random numbers. 
//This will generate a random permutation, unless two of the random numbers generated are the same. 
//This can be eliminated either by retrying these cases, 
//or reduced to an arbitrarily low probability by choosing a sufficiently wide range of random number choices.
//The second, generally known as the Knuth shuffle or Fisher-Yates shuffle, 
//is a linear-time algorithm (as opposed to the previous O(n log n) algorithm if using 
//efficient sorting such as mergesort or heapsort) 
//which involves moving through the pack from top to bottom, 
//swapping each card in turn with another card from a random position in 
//the part of the pack that has not yet been passed through (including itself). 
//Providing that the random numbers are unbiased, this will always generate a random permutation.
/*************************************************************************************************************************************/
//Q: Given a string where there are numbers and some numbers are repeated, e.g. 13413124...,
//design a data structure for it and the data structure should store positions of each number.
//A: we could use array of structure. In this the index of the array will be the number and the 
// structure will contain the list of all the numbers.
//struct List
//{
//	int position;
//	struct List *next;
//};
//
//struct List repeatedList[10];
/*************************************************************************************************************************************/
//Q: If there is a set of numbers like: 1,0,0,0,1,1,0,0,1,1,1,0,0. How would you sort them?
//A: quick sort in one iteration or bitmap
/*************************************************************************************************************************************/
//Given an array of N elements , one element is repeated N/2 times. Find the element if such an element exists.
//The algorithm that accomplishes this task requires just two registers.

//one of its registers for temporary storage of a single item from the array; this item is the current 
//candidate for majority element. The second register is a counter initialized to 0. For each element of 
//the array, If the counter reads 0, install the current array element as the new majority candidate. 
//Then, if the current element matches the majority candidate, increment the counter; otherwise, decrement 
//the counter. At this point in the cycle, if the part of the stream seen so far has a majority element, that 
//element is in the candidate register, and the counter holds a value greater than 0."
/*************************************************************************************************************************************/
//Write a function to check if two strings are anagrams. Write a function to find all possible 
//anagrams of a given string. You are given a method isWord() to check if the string is a valid 
//word in a dictionary. Assuming that preprocessing 
//can be done what preprocessing will u do in order to speed up the process of finding anagrams.

//A : The judgment of whether two words are anagram is simple. We can use bitmap method to record the letters.
//Each word is corresponding to an array whose size is 26 with each index representing a letter. The value of 
//the elements in the array represent the frequency a certain letter is appeared in the word. If two words are
//anagram, the two corresponding record array must be the same.

//A : We need to reprocess all the words in the dictionary using hash table. The hash value calculated for each words
//should not be affected by the order of letters within a word. So we can get the anagram words of a certain word within
//O(n) time complexity.
/*************************************************************************************************************************************/
//Given a n*m matrix having numbers such that each row and each column sorted. Now print the numbers in present in the matrix in sorted order

//A: Merge sort. O(MNlog(N))
/*************************************************************************************************************************************/
//Q: Prove the time complexity of quick sort is nLog(n)

//A: When two partitions of equal length is produced during the recursive partitioning step,its 
//considered to be the best case behavior for Quick sort.
//
//In order to sort n elements,the running time is in o(n log(n)). This is because the recursion depth is 
//log(n) and on each level there are n elements to be treated.
//
//During the recursive step ,if we get an unbalanced partition, i.e. one partition containing one 
//element and the other one containing the remaining n-1 elements,we call this the worst case for quick sort. Then the 
//recursion depth is n-1 and for n such levels,it would be n*n-1 which gives quick sort the running time of o(n^2).
/*************************************************************************************************************************************/
//Q: given two binary search trees, merge them in O(n) time with O(1) space
//A: Not a satisfied algorithm prompted, here is my solution which satisfied the question but end up with an inbanlanced BST.
//Make the first BST to a sorted link says L1 and same to the second says L2, merg L1 and L2 ended up a BST in the worset case.
/*************************************************************************************************************************************/
//Q: In our indexes, we have millions of URLs each of which has a link to some page contents, that is, 
//URL->contents. Now, suppose a user types a query with wild cards *, which represent 0 or multiple 
//occurrences of any characters, how do you build the indexes such that such a type of query can be 
//executed efficiently by finding all corresponding URLs->contents efficiently. 
//For example, given a query http://www.*o*ve*ou.com. You need to find iloveyou.com, itveabcu.com, etc. 

//A: Trie tree
/*************************************************************************************************************************************/
//find the common node in two singly LL

//A: Get the length of the two list and get the difference of the length of the two lists. Start from the longer link and 
//move forward for several steps equal to the difference just calculated. And than start to compare the nodes of the two links
//with in a loop, in each iteration to see whether the two current nodes have the same address, if not, proceed one node for each
//list until they reached the end. If the nodes with same address is found, then this address is the common node, if the end of both
//lists are reached at last, there is no common node the two lists shares
/*************************************************************************************************************************************/
//Q: Least common ancestor of two nodes in a binary tree, BST ? complexity ?
//A: If the value of the two nodes are a and b (says a < b). Go through the tree and find the first node, says c, whose value is larger than a 
//and less than b.
/*************************************************************************************************************************************/
//Q: Show that second smallest of n elements can be found with n + logn -2 in worst case..
//A: Build a competing tree from the bottom to the top. For example, in the first round, compare the adjacent number and get the winner,
//in which case is the bigger one. And then, do other round of comparation based on the winner of the previous round. So, a competing
//tree is built from the bottom to the top and the root of this tree is the biggest one, this took n-1 comparation. So, in the next
//step, go down the tree from the root, get the biggest number which compared with the root of the competing tree, which is the second biggest
//number. This step compares log(n)-1 time, so totally n+log(n)-2 times of comparations are needed.
/*************************************************************************************************************************************/
