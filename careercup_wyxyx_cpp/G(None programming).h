//Q: How could you distinguish web pages which Koreans or Japanese read?
//A: The percentage of the unicode for a certain language

//Q: You need read a lot of records, you don't know how many records here
//before you complete it. After you read all those records, you need select
//one record randomly.In another words, every record has same chance to be
//selected. The memory is limited, that means you cannot store all those
//records at one time.
//A: here is a short explanation: at any moment, if you have seen K records so far, 
//each record should have a probability of 1/K to be chosen.
//Recursively, when you see the Kth record, you pick it with 1/K probability, otherwise you just keep your previous pick.

//Q: Design a efficient cache, supporting retrieval of maximum element in cache along with other normal cache operations.
//Suggest data structures tbo be used,also tell the complexities for each of the operations.
//A: My answer is max heap combined with linked hash map	

//Q:given a 3 number discrete random number generator {1,2,3} , 
//how can you design a 5 number random generator ? What is the average number of trials necessary ?

//A:
//int rand5()
//{
//	int x=rand3(();int y=rand3();
//	if(x+y==3 || x+y==5) return rand5();
//	if(x==1 && y==1) return 1;
//	if(x==2 && y==1) return 2;
//	if(x==2 && y==2) return 3;
//	if(x==1 && y==2) return 4;
//	if(x==3 && y==3) return 5;
//}

//Q: Given a tree in which each node is an integer and an array with a set of integers, 
//determine if all the elements of the array are present in the tree by visiting each node in the tree at most once.

//A: Put all the elements in the array to a hash table, so the search for each element will cost O(n). Then, allocate 
//an array with the size same to the given array, this array is used to record whether the corresponding element has been
//traveled or not. Then, travel through the tree, if the element can be found in the hash table, mark it in the recording
//array. When the traveling is finished, go through the recording array to see whether all the elements are marked.

//Q: given an array of n elements, find if there is a subset of 3 elements sum up to value T with time complexity O(nlgn).
//A: Only O(n^2) can be reached, :P. 

//Q: Given a document and a query of K words, how do u find the smallest window that covers all the words 
//at least once in that document? (given you know the inverted lists of all K words, that is, for each word, 
//you have a list of all its occurrrences). This one is really hard. Could someone propose an algorithm in O(n)?

//A : As all the inverted lists are sorted, we can merge the those k lists to one sorted list.
//Then we try to reduhhhhce the window from two sides and we stopped at the point eliminate which will
//eliminate the occurrence of a particular word.

//Q: Given an array of numbers, write a function which will 
//return another array containing the elements of the previous array but in random order. 

//A: Don't even know how many times google asked this question

//Q: Given an array of integers(both positive and negative) divide the 
//array into two parts(sub-arrays) such that the difference between the sum of elements in each array is minimum????

//A: The problem is very similar/identical to the Knapsack problem which is NP hard 
//(and the decision version is NP complete). In other words, there is no known polynomial-time 
//algorithm that would guarantee to find optimal solution. There are pseudo-polynomial-time algorithms (using DP) 
//that solve this. Note that pseudo-polynomial is in the size of the input and not size of n!!! 
//In other words, if all the numbers are within a given range, then there's a polynomial time algorithm that 
//solves this problem. The difficulty arises when the numbers are arbitrarily big. See wikipedia for more details.

//Q: compare the advantage and disadvantage of BST and hash
//A: To find a element, hash cost O(1) if hash function is well designed, However, log(n) for a BST at the best situation
//when BST is balanced, however O(n) in worst if the BST is just a sorted link.
//For insertion, the hash table have to minimize the collision and the BST should keep balance.
//Hash table will took extra memory, BST not.

//Q: You are given N blocks of height 1…N. In how many ways can you arrange these blocks in a row such that 
//when viewed from left you see only L blocks (rest are hidden by taller blocks) and when seen from right 
//you see only R blocks? Example given N=3, L=2, R=1 there is only one arrangement {2, 1, 3} while for N=3, 
//L=2, R=2 there are two ways {1, 3, 2} and {2, 3, 1}.
//A: Simplify this problem at first. Just look from the left to see to see how many combinations satisfied the
//condition that you only see L blocks from your perspective.For example if n == 13, L == 3, your current choice 
//are 3, 7, 10, so the combinations you got at this point is (3-1)!*(7-3)!*(10-7)!*(13-10)!, clear???

//Q: Given a very large data stream, you don't know how many elements containing, randomly pick up k numbers
//A: Maintain an K number array and put first k numbers in this array. For Xth number, there is k/X possibility
//to choose this number, and take the place of the chosen Kth number randomly.

//Q: Design an algorithm to implement google like smart calculator. No button in the calculator. 
//Just enter something like "98F to C" and it should convert 98 degree fahrenheit to celsius.
//Calculation part is easy. Design the algorithm to understand what operation needs to be done, 
//whether its temperature conversion or simple mathematics or length conversion

//A: Just treat this kind of conversion as another kind of calculation with its syntax supported by this calculator.
//Nothing different to plus or minus operator. So, the word "To" is a key world here which represents 
//an operation, just like plus("+"). What we need to do is to add the syntax and lexical support for
//this kind of conversion which we learnt from the compiler principle. Like the calculation of other operator,
//we can do the parsing logic by top to
//bottom recursive parsing. We also need to recognize the these two kind of temperature measurement in 
//lexical parsing. And then, use a function to calculate the result of the conversion. The "To" key word here can
//represent different kind of conversion, not only temperature conversion by also other kind of conversion, like 
//the conversion of currency, conversion from meter to inch, whatever. They all can use the key word "To" as operator
//just like plus operator. The key for the parsing program to different various conversion is judged by the result of 
//lexical analyze for the left operant and the right operant of operator "To".

//Q: Given a function that takes in an integer input and gives out an integer:
//int func(int input);
//This function is deterministic. It always gives the same output value for a given input. Say func(8) = 7 whenever it is called.
//Now this function is called multiple times in a loop. This would generate a stream of integers [which are the outputs 
//of that function for different inputs to the function]. He asked me what is the length of this loop ? 
//When i said i didn't understand by what he meant, he said, give me the count of how many numbers are repeated and how many 
//numbers are not repeated. He said there is very limited memory: you can store only a certain number of integers at a time, but not all of them.

//A: This problem is just similar as to judge a single linked loop got a loop in it or no. So, with in a loop, we can record the out put
//of this function by two callings, one is called every two times and the other is called every time. So, we record the out put of both the
//more frequently called functions and the out put of the function which is called every two times and will find a time when the two out puts
//are the same, this is one of the repeated numbers. Then, we record the times of callings until the same out put pumped out again.
//bool b = true;
//while (r1 != r2)
//{
//	if (b) r1 = func(r1);
//	b = !b;
//	r2 = func(r2);
//}

//Q: An rpc server is given which receives millions of requests a day. Each request i takes processing time Ti to get processed. 
//We want to find the 65th percentile processing time (when processing times are sorted according to their values in increasing
//order) at any moment. We cannot store processing times of all the requests of the past as the number of requests is very large. 
//And so the answer need not be exact 65th percentile, you can give some approximate answer i.e. processing time which 
//will be around the exact 65th percentile number.

//A1: I guess we can do it in a hierarchical way. We only calculate the 65-th processing time in every window of 1000 
//requests. Put the 65-th processing time of every 1000 requests into another window (a higher level), which records 1000 
//values again. On a higher higher level, 
//we can record another 1000. As a result, we can record 10^9 requests by using a storage of 3000 requests.

//A2: We can reduce the problem something like this:
//You have very large stream of numbers coming, and you need to pick up k numbers from this large set, 
//such that the probability of each of these numbers picked is equal. So at any time using these k numbers, 
//find the 65th percentile out of these. The final solution is more accurate, with higher the value of k. 
//Lets say, you have trillion numbers coming in, and you just have size of say only Million.
//The solution to the new problem is: here the value of K is Million.
//Select the first K numbers from the stream, then with with every new number coming, select the number 
//with the probability of k/N. If selected then eliminate one of the numbers from the set of K with the probability of 1/k. 
//This ensures that all the numbers in the set are all selected with equal probability.
//Note: "N" is the current total of all the numbers arrived in the stream.

//Q: An array of integers of size n-1, all the elements are form [1,n]. Find the missing number. 

//A: Read the first bit to judge a number is even or odd. So, if one number is misplace, all the even-odd 
//property following is misplaced. So, if a number at index i is misplaced, all the number behind it is misplaced,
//if it is not, all the number in front of it is not missing. DO this by binary search to reach logn time complexity