#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main()
{
	string words;
	int vowel = 0, consonant = 0, other = 0;
	cout << "Enter words (q to quit): \n";

	while((cin >> words) && (words != "q"))		// cin会自动跳过空白字符
	{
		if(isalpha(words[0]))
		{
			switch(words[0])
			{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':
					vowel++;
					break;
				default:
					consonant++;
			}
		}
		else
			other++;
	}

	cout << vowel << " vowels\n" << consonant << " consonants\n"
	<< other << " others.\n";

	return 0;
}
