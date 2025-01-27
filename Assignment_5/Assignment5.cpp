// Assignment5.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include <memory>
#include <functional>

/*
* Author Himanshu Kohli
*/


using namespace std;
using namespace std::placeholders;
// Solution 1 starts

/*
* Checks whether the phrase is palindrome or not
* @param: phrase(const string): inputs the string
* @return: returns true or falses depending whether the string is a palindrome or not 
*/

bool is_palindrome(const string& phrase) 
{
	string newPhrase;
	bool result;

	remove_copy_if(phrase.begin(), phrase.end(), back_inserter(newPhrase), [](char p) {return !isalpha(p); });
	transform(newPhrase.begin(), newPhrase.end(), newPhrase.begin(), [](unsigned char c) {return toupper(c); });
	result = equal(newPhrase.begin(), newPhrase.begin() + newPhrase.size() / 2, newPhrase.rbegin());
	
	return result;
}

/*
* Testter function 
* called from main to test the palindrome method
*/
void test_is_palindrome()
{
	string str_i = string("Was it a car or a cat I saw?");
	string str_u = string("Was it a car or a cat U saw?");

	cout << "the phrase \"" + str_i + "\" is " + (is_palindrome(str_i) ? "" : "not ") + "a palindrome \n";
	cout << "the phrase \"" + str_u + "\" is " + (is_palindrome(str_u) ? "" : "not ") + "a palindrome \n";
	
}

//solution 1 ends


// Solution 2 starts

/*
* Returns the iterator to the second greatest element in a vector
* @param: start(Iterator): the begining iterator for the vector
* @param: finish(Iterator):the ending iterator for the vector
* @return: returns a pair which holds the iterator and boolean value 
*				true for elements with more than one distinct element
*/
template<class Iterator>
std::pair<Iterator, bool> second_max(Iterator start, Iterator finish)
{
	if (start == finish)
		return make_pair(finish, false);
	else
	{
		set<int,greater<int>> myset(start,finish);
		if (myset.size() == 1)
		{
			return make_pair(start, false);
		}
		else if(myset.size() >= 2)
		{
			auto it = myset.begin();
			advance(it, 1);
			*start = *it;
			return make_pair(start, true);
		}
		
	}
}

/*
* Tester function to print the second greatest element in the vector
* @param: vec(vector<int>): vector which has integer elements
*/
void test_second_max(vector<int> vec)
{
	auto retval = second_max(vec.begin(), vec.end());
	if (retval.second)
	{
		cout << "The second largest element in the vector is " << *retval.first << endl;
	}
	else
	{
		if (retval.first == vec.end())
		{
			cout << "List is empty, no elements " << endl;
		}
		else
		{
			cout << "Container elements are all equal to " << *retval.first << endl;
		}
	}
}

// Soution 2 ends

// Solution 3

/*
* Counts how many elements have string greater than the size
*		Using Lambda function
* @param: vec(vector<string>): Collection of strings
* @param: size(int): holds an integer value which is to checked with string length
* @return: the count of elements which has size greater than the size
*/
int countStringLambda(vector<string>& vec, int size)
{
	int counter =  count_if(vec.begin(), vec.end(), [size](string s) { return (s.size() < size); });
	return counter;
}

/*
* Retruns true if the length of the string is greater than the size
* @param: str(string): string
* @param: size(int): holds an integer value which is to checked with string length
* @return: true if string length is greater than the size
*/
bool isLessThan(const string str,const int size)
{
	return str.length() < size;
}

/*
* Counts how many elements have string greater than the size
*		Using Free function { isLessThan() }
* @param: vec(vector<string>): Collection of strings
* @param: size(int): holds an integer value which is to checked with string length
* @return: the count of elements which has size greater than the size
*/
int countStringFreeFun(vector<string>& vec, int size)
{
	return count_if(vec.begin(),vec.end(), bind(isLessThan, _1, size));
}

/*
* Class to be used a functor 
*/
class ShorterLengthThan
{
private:
	int size;
public:

	// Class Constructor
	ShorterLengthThan(int n) : size(n) { }

	/*
	* Operator overloading for operator ()
	* @param: str(string): string
	* @return: returns true if the string length is greater than size
	*/
	bool operator () (const string str) const {
		return str.length() < size;
	}
};

/*
* Counts how many elements have string greater than the size
*		Using Functor
* @param: vec(vector<string>): Collection of strings
* @param: size(int): holds an integer value which is to checked with string length
* @return: the count of elements which has size greater than the size
*/
int countStringFunctor(vector<string>& vec, int size)
{
	return count_if(vec.begin(), vec.end(), ShorterLengthThan(size));
}
// solution 3 ends

// Solution 4
/*
* Counts the characters in a given string
*/

void charFrequency()
{
	cout << "Please Enter one or more lines of text " << endl;
	cout << "To End input press Ctrl-Z in Windows and Ctrl-D in Linux" << endl;

	map<char, int> charFrequency;

	for_each(istream_iterator<char>(std::cin),istream_iterator<char>(),
		[&charFrequency](char character)->void {
		character = tolower(character);
		auto itr = charFrequency.find(character);
		if (itr != charFrequency.end())
		{
			charFrequency[character] = charFrequency[character] + 1;
		}
		else
		{
			charFrequency[character] = 1;
		}
	});
	std::cin.clear();

	for (auto it = charFrequency.begin(); it != charFrequency.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}
}
// Solution 4 ends

// Solution 5
/*
* custom comparator for the multisetUsingDefinedComparator
*/

struct cmp_by_length {
	template<class T>
	bool operator()(T const &a, T const &b) {
		return a.length() < b.length() || (a.length() == b.length() && a < b);
	}
};

/*
* Prints the elements in ascending order of length and alphabets
*/

void multisetUsingDefinedComparator()
{
	multiset<string, cmp_by_length> gibberish;
	vector<string> vec =
	{ "C","BB","A","CC","A","B","BB","A","D","CC","DDD","AAA" };

	copy(vec.begin(), vec.end(), inserter(gibberish, gibberish.begin()));
	ostream_iterator<string> out(cout, " ");
	copy(gibberish.begin(), gibberish.end(), out);

}



// Solution 5 ends
int main()
{

	// problem 1:
	test_is_palindrome();
	cout << "\n";

	// problem 2:

	std::vector<int> v1{ 1 }; // one element
	test_second_max(v1);

	std::vector<int> v2{ 1, 1 }; // all elements equal
	test_second_max(v2);

	std::vector<int> v3{ 1, 1, 3, 3, 7, 7,642,220 }; // at least with two distict elements
	test_second_max(v3);
	cout << "\n";

	// problem 3:
	std::vector<std::string> vecstr
	{ "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
		"range", "[first", "last)", "for", "which", "pred", "is", "true."
	};
	cout <<"countStringLambda(vecstr, 5): "<< countStringLambda(vecstr, 5) << endl;
	cout <<"countStringFreeFun(vecstr, 5): "<< countStringFreeFun(vecstr, 5) << endl;
	cout <<"countStringFunctor(vecstr, 5): "<< countStringFunctor(vecstr, 5) << endl;
	cout << "\n";
	
	// problem 4:
	charFrequency();
	cout << "\n";

	
	// problem 5:
	multisetUsingDefinedComparator();
	cout << "\n\n";

	
    return 0;
}


