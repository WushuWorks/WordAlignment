// WordAlignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// When given some number of separate roman letter words, contained in Textboxes, how do you align those boxes such that the baseline is consistent throughout them?
// 
// Write a function that returns a correct Y-offset for each Textbox given print it with the provided function

#include <iostream>
#include <random>

using namespace std;

const size_t A = 3;

class Textbox {
	public:
		int width, height, baseline;

		Textbox(int w, int h, int b) {
			width = w; // Words in the box
			height = h; // Tallest letter in box
			baseline = b; // Distance from the bottom the text baseline is
		}
};

void Textprint(Textbox text[], int offsets[], int size) {

	// nested for loop go brr
	for (int i = 0; i < size; ++i) {
		for (int z = 0; z < text[i].width; z++) {
			for (int y = 0; y < offsets[i]; y++) {
				cout << '-';
			}
			for (int x = 0; x < text[i].height; x++) {
				if (text[i].baseline == x)
					cout << "|";
				else
					cout << 0;
			}
			cout << endl;
		}
		cout << endl;
	}
};

// My O(n) solution
void findOffset(int(&offsets)[A], Textbox text[A]) {
	int highestBaseline = 0;

	// Find the highest baseline O(n)
	for (int i = 0; i < A; i++) {
		if (text[i].baseline > highestBaseline) {
			highestBaseline = text[i].baseline;
		}
		else {
			continue;
		}
	}

	// Calculate and store offsets O(n)
	for (int x = 0; x < A; x++) {
		offsets[x] = highestBaseline - text[x].baseline;
	}
}

//Better rand int function
int random(int range_from, int range_to) {
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>    distr(range_from, range_to);
	return distr(generator);
}

//Test a solution function
void test(void(*solution)(int(&offsets)[A], Textbox text[A]), int iterations) {
	const int MAXHEIGHT = 10;

	cout << "\nBeginning additional tests...\n\n";

	for (int i = 0; i < iterations; i++) {
		cout << "\nTest #" << i+1 << endl << endl;

		int height = random(3, MAXHEIGHT);
		Textbox t1 = Textbox(random(3, 10), height, random(0, height - 1));
		height = random(3, MAXHEIGHT);
		Textbox t2 = Textbox(random(3, 10), height, random(0, height - 1));
		height = random(3, MAXHEIGHT);
		Textbox t3 = Textbox(random(3, 10), height, random(0, height - 1));
		Textbox t[3] = { t1, t2, t3 };
		int newOffsets[3] = { 0, 0, 0 };

		solution(newOffsets, t);

		Textprint(t, newOffsets, 3);
	}
}

int main()
{

	std::cout << "Hello WordAlignment!\n\n";

	// baselines are counted from 0, so [0,h)
	Textbox t1 = Textbox(5, 6, 1);
	Textbox t2 = Textbox(5, 7, 0);
	Textbox t3 = Textbox(4, 4, 3);
	Textbox t[3] = { t1, t2, t3 };
	int offsets[3] = { 0, 0, 0 };

	//My O(n) solution
	findOffset(offsets, t);

	//Implement your own here!

	// Insert offsets in func below
	Textprint(t, offsets, 3);
	// Hook in your solution here for testing
	test(findOffset, 3);
}

