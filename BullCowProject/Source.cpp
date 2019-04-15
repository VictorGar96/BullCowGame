////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// ARCHIVO MAIN ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "FBullCowGame.h" /// Incluimos el archivo de cabecera

/// Unreal String type and int type
using FString = std::string;
using int32   = int; 

/// Funciones 
void    PrintIntro();
void    PlayGame();
FString GetGuess();
bool    bWantToPlayAgain();

/// Variable con la cual accedemos a FBullCowGame.cpp
FBullCowGame BCGame;

int main()
{
	/// Booleano con el cual comprobamos si el jugador quiere volver a jugar
	bool gameOn = false;

	/// Do while, donde incluimos toda la lógica del juego
	do
	{
		PrintIntro();
		PlayGame();
		gameOn = bWantToPlayAgain();

	}while (gameOn);

	return 0;
}

/// Función con la cual imprimimos la intro donde le indicamos la cantidad de letras que tiene la palabra 
void PrintIntro()
{
	
	std::cout << "Welcome..\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWord().length() 
			  << " letter isogram Im thinking of? \n";
}

/// Función que resetea los valores:
	/// - Intentos
	/// - Aciertos
	/// - Palabra
	/// - 
void PlayGame()
{
	BCGame.Reset();
	
	for (int32 i = BCGame.GetCurrentTry(); i < BCGame.GetMaxTries(); i++)
	{
		FString guess = GetGuess();

		FBullCowCount bullCowCount = BCGame.SumitGuess(guess);

		EGuessStatus status = BCGame.CheckGuessValidity(guess);

		std::cout << std::endl << "Bulls = " << bullCowCount.Bulls << std::endl;
		std::cout << "Cows  = " << bullCowCount.Cows  << std::endl;

		if (bullCowCount.Bulls == guess.length())
		{
			std::cout << "CONGRATS!!! YOU WON" << std::endl;
			break;
		}

		std::cout << "Number of tries: " << i + 1 << " of " << BCGame.GetMaxTries() << std::endl;
	}
}

/// Función de tipo string que recoge y devuelve la palabra introducida por el usuario.
FString GetGuess()
{
	FString  guess = "";
	EGuessStatus status = EGuessStatus::Invalid;

	do
	{
		std::cout << "Enter your guess: ";
		std::getline(std::cin, guess);

		EGuessStatus status = BCGame.CheckGuessValidity(guess);

		switch (status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without reapeating letters. \n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWord().length() << " letter word. \n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter a lower case letters. \n";
			break;
		case EGuessStatus::Not_Letters:
			std::cout << "Please enter letters only. \n";
		case EGuessStatus::OK:
			std::cout << "Valid \n";
			return guess;
		}
	} while (status != EGuessStatus::OK);

	return guess;
}

/// Función de tipo bool en la que comprobamos si el usuario quiere volver a jugar
/// devolviendo true si ha pulsado la letra "y".
bool bWantToPlayAgain()
{ 
	std::cout << "Do you want to play again? (y/n)";
	FString response = " ";

	std::getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');
}
