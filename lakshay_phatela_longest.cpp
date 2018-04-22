#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	int i = 0; // index for words array
	int j = 0; // index for word_length array
	int k, l; // indices for sorting words and word_length array
	string word;
	string words[10];
	int word_length[10];



	int lowest = 0;
	int highest = 9;
	int medium = (lowest + highest) / 2;

	ifstream data_file;
	data_file.open("/usr/share/dict/words");
	if (!data_file)
	{
		cout << "Can not open text file.\n";
		return 0;
	}

	//storing first 10 words in an array and then finding 10 longest words
	while (data_file >> word)
	{
		if (i<10)
		{
			for (j = 0; word[j] != '\0'; j++)
			{
			}
			word_length[i] = j;
			words[i] = word;
			if (i == 9)    //sorting elements is words and word_length array depending on their size using insertion sort in O(nlogn) time complexity
			{
				int temp_length = 0;
				string temp_word;
				for (k = 0; k < 9; k++)
				{
					l = k + 1;
					while (l > 0)
					{
						if (word_length[l] < word_length[l - 1])
						{
							temp_length = word_length[l];
							temp_word = words[l];
							word_length[l] = word_length[l - 1];
							words[l] = words[l - 1];
							word_length[l - 1] = temp_length;
							words[l - 1] = temp_word;
							l--;
						}
						else
							break;
					}
				}
			}
			i++;
		}
		else
		{
			for (j = 0; word[j] != '\0'; j++) 
			{
			}
				
			if (j == word_length[medium]) //best case scenario
			{
				highest = medium - 1;
				for (int x = 0; x <= highest; x++)
				{
					word_length[x] = word_length[x + 1];
					words[x] = words[x + 1];
				}
				word_length[highest] = j;
				words[highest] = word;
				highest = 9;
			}
			else if (j < word_length[medium])  // average case scenario
			{
				highest = medium - 1;
				for (int y = highest; y >= 0; y--)
				{
					if (j > word_length[y])
					{
						for(int p = 0; p < y; p++)
						{
						word_length[p] = word_length[p + 1];
						words[p] = words[p + 1];
						}
						word_length[y] = j;
						words[y] = word;
						highest = 9;
						break;
					}
				}
			}
			else // worst case scenario
			{
				highest = 9;
				if (j >= word_length[highest]) // best case scenario in worst case scenario
				{
					for (int q = 0; q < highest; q++)
					{
						word_length[q] = word_length[q + 1];
						words[q] = words[q + 1];
					}
					word_length[highest] = j;
					words[highest] = word;
				}
				else 
				{
					for (int z = highest-1; z >= 0; z--)
					{
						if (j > word_length[z])
						{
							for (int r = 0; r < z; r++)
							{
								word_length[r] = word_length[r + 1];
								words[r] = words[r + 1];
							}
							word_length[z] = j;
							words[z] = word;
							break;
						}
					}
				}
			}
			i++;
		}

	}
	for (int k = 0; k <= 9; k++)
	{
		cout << words[k] << endl << word_length[k] << endl;
	}
	return 0;
}
