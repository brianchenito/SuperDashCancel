#include "InputAI.h"





InputAI::InputAI(GLFWwindow * window):InputDevice(window)
{
	std::cout << " robot created\n";
	std::vector<std::vector<bool>> groundedoffense = 
	{
		std::vector<bool>{ 0,0,1,0,1,0},
		std::vector<bool>{ 0,0,0,1,1,0},
		std::vector<bool>{ 0,0,0,1,0,1},
		std::vector<bool>{ 0,0,1,0,0,1},
	};
	std::vector<std::vector<bool>> groundeddefence =
	{
		std::vector<bool>{ 0,1,1,0,0,0},
		std::vector<bool>{ 0,1,0,1,0,0},
		std::vector<bool>{ 0,0,0,1,1,0},
		std::vector<bool>{ 0,0,1,0,0,0},
	};
	std::vector<std::vector<bool>> jumpin =
	{
		std::vector<bool>{ 1,0,1,0,0,0},
		std::vector<bool>{ 0,0,0,1,0,0},
		std::vector<bool>{ 0,0,0,1,1,0},
		std::vector<bool>{ 0,0,1,0,0,1},
	};
	
	std::vector<std::vector<bool>> dashin =
	{
		std::vector<bool>{ 0,0,1,0,0,0},
		std::vector<bool>{ 0,0,0,0,0,0},
		std::vector<bool>{ 0,0,1,0,0,0},
		std::vector<bool>{ 0,0,1,0,0,1},
	};


	std::vector<std::vector<bool>> dashin2 =
	{
		std::vector<bool>{ 0,0,0,1,0,0},
		std::vector<bool>{ 0,0,0,0,0,0},
		std::vector<bool>{ 0,0,0,1,0,0},
		std::vector<bool>{ 0,0,0,1,0,1},
	};
	Sequences.push_back(groundedoffense);
	Sequences.push_back(groundeddefence);
	Sequences.push_back(jumpin);
	Sequences.push_back(dashin);
	Sequences.push_back(dashin2);
	for (int i = 0; i < 8; i++)
	{
		pressed[i] = false;
		held[i] = false;
	}
	//currentseq = rand() % (Sequences.size() - 1);
	currentseq = 0;
	seqstage = 0;
	timer = rand() % 15;
}

InputAI::~InputAI()
{
}

void InputAI::FixedStep()
{
	//std::cout << "Robot Tick\n";
	inputThisFrame = false;
	for (int i = 0; i < 6; i++)
	{
		//std::cout << "Robot"<<(Sequences[currentseq])[seqstage][i]<<"\n";
		pressed[i] = false;
		if ((Sequences[currentseq])[seqstage][i])
		{
			pressed[i] = !held[i];

			held[i] = true;
			inputThisFrame = true;
			//std::cout << "Robot PRESSED " << i << "\n";
		}
		else held[i] = false;

	}
	timer--;
	if (timer <=0) 
	{
		timer = rand() % 15;
		seqstage++;
		if (seqstage >= (Sequences[currentseq]).size()) 
		{
			seqstage = 0;
			currentseq = rand() % (Sequences.size() - 1);
		}

	}

}

bool InputAI::Pressed(Input b)
{
	return pressed[(int)b];
}

bool InputAI::Held(Input b)
{
	return held[(int)b];
}
